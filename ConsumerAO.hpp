/*------------------------------------------------------------------------------
File: ConsumerAO.hpp

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
#ifndef _ConsumerAO_HPP_
#define _ConsumerAO_HPP_

#include "EventBasedAO.hpp"
#include "ConsumerAdapter.hpp"

namespace gx {

class ConsumerAO: public EventBasedAO
{
public:
    ConsumerAO();
    virtual ~ConsumerAO();

    // EventBasedAO interface
    virtual void init();

private:
    template< class T > inline void onEvent();

    ConsumerAdapter m_adapter;
};

} // End namespace

#endif
