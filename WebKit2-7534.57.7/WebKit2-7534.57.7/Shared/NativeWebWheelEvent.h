/*
 * Copyright (C) 2011 Apple Inc. All rights reserved.
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

#ifndef NativeWebWheelEvent_h
#define NativeWebWheelEvent_h

#include "WebEvent.h"

#if PLATFORM(MAC)
#include <wtf/RetainPtr.h>
OBJC_CLASS NSView;
#elif PLATFORM(QT)
#include <qgraphicssceneevent.h>
#elif PLATFORM(GTK)
#include <GOwnPtrGtk.h>
typedef union _GdkEvent GdkEvent;
#endif

namespace WebKit {

class NativeWebWheelEvent : public WebWheelEvent {
public:
#if PLATFORM(MAC)
    NativeWebWheelEvent(NSEvent *, NSView *);
#elif PLATFORM(WIN)
    NativeWebWheelEvent(HWND, UINT message, WPARAM, LPARAM);
#elif PLATFORM(QT)
    explicit NativeWebWheelEvent(QGraphicsSceneWheelEvent*);
#elif PLATFORM(GTK)
    NativeWebWheelEvent(const NativeWebWheelEvent&);
    NativeWebWheelEvent(GdkEvent*);
#endif

#if PLATFORM(MAC)
    NSEvent* nativeEvent() const { return m_nativeEvent.get(); }
#elif PLATFORM(WIN)
    const MSG* nativeEvent() const { return &m_nativeEvent; }
#elif PLATFORM(QT)
    const QGraphicsSceneWheelEvent* nativeEvent() const { return m_nativeEvent; }
#elif PLATFORM(GTK)
    const GdkEvent* nativeEvent() const { return m_nativeEvent.get(); }
#endif

private:
#if PLATFORM(MAC)
    RetainPtr<NSEvent> m_nativeEvent;
#elif PLATFORM(WIN)
    MSG m_nativeEvent;
#elif PLATFORM(QT)
    QGraphicsSceneWheelEvent* m_nativeEvent;
#elif PLATFORM(GTK)
    GOwnPtr<GdkEvent> m_nativeEvent;
#endif
};

} // namespace WebKit

#endif // NativeWebWheelEvent_h