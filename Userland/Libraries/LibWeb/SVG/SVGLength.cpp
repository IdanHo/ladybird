/*
 * Copyright (c) 2022, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/SVG/SVGLength.h>

namespace Web::SVG {

WebIDL::ExceptionOr<JS::NonnullGCPtr<SVGLength>> SVGLength::create(JS::Realm& realm, u8 unit_type, float value)
{
    return MUST_OR_THROW_OOM(realm.heap().allocate<SVGLength>(realm, realm, unit_type, value));
}

SVGLength::SVGLength(JS::Realm& realm, u8 unit_type, float value)
    : PlatformObject(realm)
    , m_unit_type(unit_type)
    , m_value(value)
{
}

JS::ThrowCompletionOr<void> SVGLength::initialize(JS::Realm& realm)
{
    MUST_OR_THROW_OOM(Base::initialize(realm));
    set_prototype(&Bindings::ensure_web_prototype<Bindings::SVGLengthPrototype>(realm, "SVGLength"));

    return {};
}

SVGLength::~SVGLength() = default;

// https://www.w3.org/TR/SVG11/types.html#__svg__SVGLength__value
WebIDL::ExceptionOr<void> SVGLength::set_value(float value)
{
    // FIXME: Raise an exception if this <length> is read-only.
    m_value = value;
    return {};
}

}
