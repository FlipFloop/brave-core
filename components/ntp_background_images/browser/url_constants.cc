/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/ntp_background_images/browser/url_constants.h"

namespace ntp_background_images {

const char kBrandedWallpaperHost[] = "branded-wallpaper";
const char kLogoPath[] = "logo.png";
const char kWallpaperPathPrefix[] = "wallpaper-";
const char kSuperReferralPath[] = "super-referral/";
const char kSponsoredImagesPath[] = "sponsored-images/";
const char kSuperReferralMappingTableURL[] =
    "https://mobile-data.s3.brave.com/superreferrer/map-table.json";
const char kSuperReferralMappingTableDevURL[] =
    "https://mobile-data-dev.s3.brave.software/superreferrer/map-table.json";

}  // namespace ntp_background_images
