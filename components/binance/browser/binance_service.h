/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BINANCE_BROWSER_BINANCE_SERVICE_H_
#define BRAVE_COMPONENTS_BINANCE_BROWSER_BINANCE_SERVICE_H_

#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/callback_forward.h"
#include "base/containers/queue.h"
#include "base/files/file_path.h"
#include "base/macros.h"
#include "base/memory/scoped_refptr.h"
#include "base/memory/weak_ptr.h"
#include "base/scoped_observer.h"
#include "components/keyed_service/core/keyed_service.h"
#include "url/gurl.h"

namespace base {
class FilePath;
class SequencedTaskRunner;
}  // namespace base

namespace content {
class BrowserContext;
}  // namespace content

namespace network {
class SharedURLLoaderFactory;
class SimpleURLLoader;
}  // namespace network

class Profile;

const char oauth_path_access_token[] = "/oauth/token";
const char oauth_path_account_balances[] = "/oauth-api/v1/balance";
const char oauth_path_convert_quote[] = "/oauth-api/v1/ocbs/quote";

const char api_path_ticker_price[] = "/api/v3/ticker/price";
const char api_path_ticker_volume[] = "/api/v3/ticker/24hr";

class BinanceService : public KeyedService {
 public:
  explicit BinanceService(content::BrowserContext* context);
  ~BinanceService() override;

  using GetAccountBalancesCallback = base::OnceCallback<
      void(const std::map<std::string, std::string>&, bool success)>;
  bool GetAccountBalances(GetAccountBalancesCallback callback);
  using GetAccessTokenCallback = base::OnceCallback<void(bool)>;
  bool GetAccessToken(const std::string& code,
      GetAccessTokenCallback callback);
  using GetConvertQuoteCallback = base::OnceCallback<void(const std::string)>;
  bool GetConvertQuote(const std::string& from,
      const std::string& to,
      const std::string& amount,
      GetConvertQuoteCallback callback);
  using SetCodeChallengeCallback = base::OnceCallback<void(bool)>;
  void SetCodeChallenge(const std::string& verifier,
      const std::string& challenge,
      SetCodeChallengeCallback callback);
  bool SetAccessTokens(const std::string& access_token,
                       const std::string& refresh_token);
  bool SetCodeChallengePref(const std::string& verifier, const std::string& challenge);
  using GetTickerPriceCallback = base::OnceCallback<void(const std::string&)>;
  using GetTickerVolumeCallback = base::OnceCallback<void(const std::string&)>;
  bool GetTickerPrice(const std::string& symbol_pair,
      GetTickerPriceCallback callback);
  bool GetTickerVolume(const std::string& symbol_pair,
      GetTickerVolumeCallback callback);
  std::string GetBinanceTLD();
  std::string GetOAuthClientUrl();

 private:
  static GURL oauth_endpoint_;
  static GURL api_endpoint_;
  using SimpleURLLoaderList =
      std::list<std::unique_ptr<network::SimpleURLLoader>>;

  using URLRequestCallback =
      base::OnceCallback<void(const int, const std::string&,
                              const std::map<std::string, std::string>&)>;

  base::SequencedTaskRunner* io_task_runner();
  void OnGetConvertQuote(GetConvertQuoteCallback callback,
                           const int status, const std::string& body,
                           const std::map<std::string, std::string>& headers);
  void OnGetAccessToken(GetAccessTokenCallback callback,
                           const int status, const std::string& body,
                           const std::map<std::string, std::string>& headers);
  void OnGetAccountBalances(GetAccountBalancesCallback callback,
                           const int status, const std::string& body,
                           const std::map<std::string, std::string>& headers);
  void OnGetTickerPrice(GetTickerPriceCallback callback,
                        const int status, const std::string& body,
                        const std::map<std::string, std::string>& headers);
  void OnGetTickerVolume(GetTickerVolumeCallback callback,
                        const int status, const std::string& body,
                        const std::map<std::string, std::string>& headers);
  bool OAuthRequest(const GURL& url, const std::string& post_data,
                    URLRequestCallback callback);
  bool LoadTokensFromPrefs();
  bool IsUnauthorized(int status);
  void OnURLLoaderComplete(
      SimpleURLLoaderList::iterator iter,
      URLRequestCallback callback,
      const std::unique_ptr<std::string> response_body);

  scoped_refptr<base::SequencedTaskRunner> io_task_runner_;
  std::string access_token_;
  std::string refresh_token_;
  std::string code_challenge_;
  std::string code_verifier_;

  content::BrowserContext* context_;
  scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory_;
  SimpleURLLoaderList url_loaders_;
  base::WeakPtrFactory<BinanceService> weak_factory_;

  DISALLOW_COPY_AND_ASSIGN(BinanceService);
};

#endif  // BRAVE_COMPONENTS_BINANCE_BROWSER_BINANCE_SERVICE_H_
