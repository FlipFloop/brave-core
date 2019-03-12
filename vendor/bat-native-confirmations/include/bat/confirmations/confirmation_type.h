/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_CONFIRMATIONS_CONFIRMATION_TYPE_H_
#define BAT_CONFIRMATIONS_CONFIRMATION_TYPE_H_

#include "bat/confirmations/export.h"

namespace confirmations {

static char kConfirmationTypeClick[] = "click";
static char kConfirmationTypeDismiss[] = "dismiss";
static char kConfirmationTypeView[] = "view";
static char kConfirmationTypeLanded[] = "landed";

enum CONFIRMATIONS_EXPORT ConfirmationType {
  CONFIRMATION_TYPE_UNKNOWN,
  CONFIRMATION_TYPE_CLICK,
  CONFIRMATION_TYPE_DISMISS,
  CONFIRMATION_TYPE_VIEW,
  CONFIRMATION_TYPE_LANDED
};

}  // namespace confirmations

#endif  // BAT_CONFIRMATIONS_CONFIRMATION_TYPE_H_
