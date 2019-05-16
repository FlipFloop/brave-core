/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/browser/locale_helper.h"
#include "brave/components/brave_ads/browser/locale_helper_android.h"

namespace brave_ads {

LocaleHelper::LocaleHelper() = default;

LocaleHelper::~LocaleHelper() = default;

std::string LocaleHelper::GetLocale() const {
  return kDefaultLocale;
}

LocaleHelper* LocaleHelper::GetInstance() {
#if defined(OS_ANDROID)
  return  LocaleHelperAndroid::GetInstance();
#else
  // just return a dummy locale helper for all other platforms
  return base::Singleton<LocaleHelper>::get();
#endif
}

}  // namespace brave_ads
