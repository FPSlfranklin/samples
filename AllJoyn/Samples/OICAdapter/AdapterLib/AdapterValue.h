// Copyright (c) 2015, Microsoft Corporation
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
#pragma once

#include "AdapterDefinitions.h"
#include "ocstack.h"

namespace AdapterLib
{
    //
    // AdapterValue.
    // Description:
    // The class that implements BridgeRT::IAdapterValue.
    //
    ref class AdapterValue : BridgeRT::IAdapterValue
    {
    public:
        //
        // Generic for Adapter objects
        //
        virtual property Platform::String^ Name
        {
            Platform::String^ get() { return m_name; }
        }

        // Data
        virtual property Platform::Object^ Data
        {
            Platform::Object^ get() { return m_data; }
            void set(Platform::Object^ NewData) { m_data = NewData; }
        }

    internal:
        AdapterValue(
            Platform::String^ ObjectName,
            Platform::Object^ DefaultData = nullptr // For signature initialization
            );

        uint32 Set(BridgeRT::IAdapterValue^ Other);

        bool operator==(const OCRepPayloadValue& val);
        bool operator!=(const OCRepPayloadValue& val);

    private:
        // Generic
        Platform::String^ m_name;
        Platform::Object^ m_data;
    };
}   //AdapterLib