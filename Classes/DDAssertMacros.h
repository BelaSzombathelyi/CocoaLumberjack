// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2016, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
 * NSAsset replacement that will output a log message even when assertions are disabled.
 **/

#define DDAssert(condition, frmt, ...) \
    if (!(condition)) {                                                           \
        NSString *description = [@"[DDAssert] Condition = '"#condition"', " stringByAppendingString:[NSString stringWithFormat:frmt, ## __VA_ARGS__]]; \
        DDLogError(@"%@", description);                                           \
        NSAssert(NO, description);                                                \
    }

#define DDAssertCondition(condition) \
    if (!(condition)) {                                                           \
        NSString *description = @"[DDAssertCondition] Condition = '"#condition"'"; \
        DDLogError(@"%@", description);                                           \
        NSAssert(NO, description);                                                \
    }

#define DDAssertFail(frmt, ...) \
  NSString *description = [@"[DDAssertFail] " stringByAppendingString:[NSString stringWithFormat:frmt, ## __VA_ARGS__]]; \
  DDLogError(@"%@", description);                                           \
  NSAssert(NO, description);


#define DDAssertNotMainThread() \
  if (!NSThread.currentThread.isMainThread) {                                                           \
    NSString *description = @"[DDAssertMainThread] It does not run on main thread!"; \
    DDLogError(@"%@", description);                                           \
    NSAssert(NO, description);                                                \
}
