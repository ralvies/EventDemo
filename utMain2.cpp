/*------------------------------------------------------------------------------
File: utMain.cpp

Description:
This test demonstrates the use of a ConsumerAO object using a Hamburger and a
Coke object as events.

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
#include "EventMgr.hpp"
#include "Hamburger.hpp"
#include "Coke.hpp"
#include "ConsumerAO.hpp"

using namespace gx;

//------------------------------------------------------------------------------
void test1()
{
    // Initialization
    EventMgr &events = EventMgr::instance();
    ConsumerAO consumer;

    // Made to order
    Hamburger hamb;
    Coke coke;

    // Deliver the order
    events.notify( hamb );
    events.notify( coke );

    // Make another order
    hamb.makePlain();
    coke.size( 12 );

    // Deliver
    events.notify( hamb );
    events.notify( coke );

    // Eat up!
    consumer.start();
}

//------------------------------------------------------------------------------
int main()
{
    test1();
    return 0;
}
