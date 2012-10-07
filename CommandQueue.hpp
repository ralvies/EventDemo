/*------------------------------------------------------------------------------
File: CommandQueue.hpp

Description:
The CommandQueue is used for adding and retrieving Command objects in FIFO
order.

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
#ifndef _CommandQueue_HPP_
#define _CommandQueue_HPP_

#include <list>

namespace gx {

class Command;

class CommandQueue
{
public:
    CommandQueue();
    ~CommandQueue();

    // CommandQueue interface
    void add( Command *pCmd );

    bool hasNext() const;
    Command* getNext();

private:
    typedef std::list< Command* > Queue;
    Queue m_queue;
};

} // End namespace

#endif
