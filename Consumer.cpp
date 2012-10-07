/*------------------------------------------------------------------------------
File: Consumer.cpp

Description:
A consumer component illustrates how an event-driven component can be
implemented in a manner which keeps it decoupled, flexible, and easy to
interface with. The Consumer class iteself acts as an interface to an underlying
event-driven active object. Each method can be implemented using blocking or
non-blocking behavior as needed.

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
#include "Consumer.hpp"
#include "ConsumerAO.hpp"
#include "Event.hpp"

using namespace gx;

namespace
{
    ConsumerAO consumer;
}

//------------------------------------------------------------------------------
Consumer::Consumer()
{
}

//------------------------------------------------------------------------------
Consumer::~Consumer()
{
}

//------------------------------------------------------------------------------
void Consumer::start()
{
    consumer.start();
}

//------------------------------------------------------------------------------
void Consumer::eat( Hamburger &hamburger, Coke &coke )
{
    Event h( hamburger );
    consumer.notify( h );

    Event c( coke );
    consumer.notify( c );
}
