/*------------------------------------------------------------------------------
File: ConsumerAO.cpp

Description:
The ConsumerAO waits for Hamburgers and Cokes to be delivered and consumes them
when they arrive.

Copyright 2012 Rob Alvies
--------------------------------------------------------------------------------
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
------------------------------------------------------------------------------*/
#include "ConsumerAO.hpp"
#include "Hamburger.hpp"
#include "Coke.hpp"
#include <functional>

using namespace gx;

//------------------------------------------------------------------------------
// inline
template< class E >
void ConsumerAO::onEvent()
{
    auto handler = [ &adapter = m_adapter ]( E &event ) mutable
    {
        adapter.consume( event );
    };

    subscribe< E >( handler );
}

//------------------------------------------------------------------------------
ConsumerAO::ConsumerAO():
m_adapter()
{
    // Normally init() would be called from the EventBasedAO, but because we
    // aren't really running in a separate thread for this demo, we have to call
    // init() from here.
    init();
}

//------------------------------------------------------------------------------
// virtual
ConsumerAO::~ConsumerAO()
{
}

//------------------------------------------------------------------------------
// virtual
void ConsumerAO::init()
{
    onEvent< Hamburger >();
    onEvent< Coke >();
}
