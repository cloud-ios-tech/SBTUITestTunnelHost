// XCTestCase+Extension.h
//
// Copyright (C) 2023 Subito.it
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#if DEBUG
    #ifndef ENABLE_UITUNNEL 
        #define ENABLE_UITUNNEL 1
    #endif
#endif

#if ENABLE_UITUNNEL

@import XCTest;
#import "SBTUITunneledHost.h"

NS_ASSUME_NONNULL_BEGIN

@interface XCTestCase (HostExtension)

@property (nonatomic, strong) SBTUITunneledHost *host;

@end

NS_ASSUME_NONNULL_END

#endif
