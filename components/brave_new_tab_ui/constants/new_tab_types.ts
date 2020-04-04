// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

export const enum types {
  NEW_TAB_STATS_UPDATED = '@@newtab/NEW_TAB_STATS_UPDATED',
  NEW_TAB_PRIVATE_TAB_DATA_UPDATED = '@@newtab/NEW_TAB_PRIVATE_TAB_DATA_UPDATED',
  NEW_TAB_PREFERENCES_UPDATED = '@@newtab/NEW_TAB_PREFERENCES_UPDATED',
  NEW_TAB_DISMISS_BRANDED_WALLPAPER_NOTIFICATION = '@@newtab/NEW_TAB_DISMISS_BRANDED_WALLPAPER_NOTIFICATION',
  NEW_TAB_SET_INITIAL_DATA = '@@newtab/NEW_TAB_SET_INITIAL_DATA',
  // Rewards Widget
  CREATE_WALLET = '@@newtab/CREATE_WALLET',
  DISMISS_NOTIFICATION = '@@newtab/DISMISS_NOTIFICATION',
  ON_ADS_ENABLED = '@@newtab/ON_ADS_ENABLED',
  ON_ADS_ESTIMATED_EARNINGS = '@@newtab/ON_ADS_ESTIMATED_EARNINGS',
  ON_ENABLED_MAIN = '@@newtab/ON_ENABLED_MAIN',
  ON_WALLET_INITIALIZED = '@@newtab/ON_WALLET_INITIALIZED',
  ON_BALANCE_REPORT = '@@newtab/ON_BALANCE_REPORT',
  ON_PROMOTIONS = '@@newtab/ON_PROMOTIONS',
  ON_PROMOTION_FINISH = '@@newtab/ON_PROMOTION_FINISH',
  ON_BALANCE = '@@newtab/ON_BALANCE',
  ON_WALLET_EXISTS = '@@newtab/ON_WALLET_EXISTS',
  SET_INITIAL_REWARDS_DATA = '@@newtab/SET_INITIAL_REWARDS_DATA',
  SET_PRE_INITIAL_REWARDS_DATA = '@@newtab/SET_PRE_INITIAL_REWARDS_DATA',
  ON_WIDGET_POSITION_CHANGED = '@@newtab/ON_WIDGET_POSITION_CHANGED',
  SET_CURRENT_STACK_WIDGET = '@@newtab/SET_CURRENT_STACK_WIDGET',
  SET_ONLY_ANON_WALLET = '@@newtab/SET_ONLY_ANON_WALLET',
  // Binance Widget
  ON_BINANCE_USER_TLD = '@@newtab/ON_BINANCE_USER_TLD',
  SET_INITIAL_ASSET = '@@newtab/SET_INITIAL_ASSET',
  SET_INITIAL_FIAT = '@@newtab/SET_INITIAL_FIAT',
  SET_INITIAL_AMOUNT = '@@newtab/SET_INITIAL_AMOUNT',
  SET_USER_TLD_AUTO_SET = '@@newtab/SET_USER_TLD_AUTO_SET',
  SET_BINANCE_SUPPORTED = '@@newtab/SET_BINANCE_SUPPORTED',
  ON_BINANCE_ACCOUNT_BALANCES = '@@newtab/ON_BINANCE_ACCOUNT_BALANCES',
  ON_BINANCE_CLIENT_URL = '@@newtab/ON_BINANCE_CLIENT_URL',
  ON_VALID_AUTH_CODE = '@@newtab/ON_VALID_AUTH_CODE',
  SET_HIDE_BALANCE = '@@newtab/SET_HIDE_BALANCE',
  CONNECT_TO_BINANCE = '@@newtab/CONNECT_TO_BINANCE',
  DISCONNECT_BINANCE = '@@newtab/DISCONNECT_BINANCE',
  ON_BTC_USD_PRICE = '@@newtab/ON_BTC_USD_PRICE',
  ON_BTC_USD_VOLUME = '@@newtab/ON_BTC_USD_VOLUME',
  ON_ASSET_BTC_VOLUME = '@@newtab/ON_ASSET_BTC_VOLUME',
  ON_ASSET_BTC_PRICE = '@@newtab/ON_ASSET_BTC_PRICE',
  ON_ASSET_USD_PRICE = '@@newtab/ON_ASSET_USD_PRICE',
  ON_ASSET_DEPOSIT_INFO = '@@newtab/ON_ASSET_DEPOSIT_INFO',
  ON_DEPOSIT_QR_FOR_ASSET = '@@newtab/ON_DEPOSIT_QR_FOR_ASSET'
}

export type DismissBrandedWallpaperNotificationPayload = {
  isUserAction: boolean
}
