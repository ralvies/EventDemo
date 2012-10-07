/*------------------------------------------------------------------------------
File: ConsumerAdapter.hpp

Description:
The ConsumerAdapter class defines a simple interface that is used to respond to
events in a uniform manner. By separating the event handling from the mechanism
used to receive the events (i.e. the ConsumerAO class) it makes it easier, if
not trivial, to test the event handling functionality directly without the need
for a test environment that sends actual events wile running in a multi-threaded
environment.

This adapter can also be used to separate how the data is received (in the form
of events) from the actual functionality that operates on that data by not
performing that functionality directly in this adapter. This further improves
the ability to test the various aspects of the code without complicated test
harnesses and setups.

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
#ifndef _ConsumerAdapter_HPP_
#define _ConsumerAdapter_HPP_

namespace gx {

class Hamburger;
class Coke;

class ConsumerAdapter
{
public:
    ConsumerAdapter();
    ~ConsumerAdapter();

    // ConsumerAdapter interface
    void consume( Hamburger &e );
    void consume( Coke      &e );
};

} // End namespace

#endif
