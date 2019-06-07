/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <WebKit/WKFoundation.h>

#if WK_API_ENABLED

#if PLATFORM(IOS)

#import <wtf/text/WTFString.h>

namespace WebKit {
class WebPageProxy;
}

@class WKWebViewConfiguration;
@protocol WKWebViewContentProvider;

@interface WKWebViewContentProviderRegistry : NSObject

- (instancetype)initWithConfiguration:(WKWebViewConfiguration *)configuration;

- (void)addPage:(WebKit::WebPageProxy&)page;
- (void)removePage:(WebKit::WebPageProxy&)page;

- (void)registerProvider:(Class <WKWebViewContentProvider>)contentProvider forMIMEType:(const String&)mimeType;
- (Class <WKWebViewContentProvider>)providerForMIMEType:(const String&)mimeType;

- (Vector<String>)_mimeTypesWithCustomContentProviders;

@end

#endif // PLATFORM(IOS)

#endif // WK_API_ENABLED
