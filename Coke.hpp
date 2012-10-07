/*------------------------------------------------------------------------------
File: Coke.hpp

Description:
The Coke class represents an event that contains data. In this case, the event
is a Coke object.

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
#ifndef _Coke_HPP_
#define _Coke_HPP_

namespace gx {

struct Coke
{
public:
    Coke( unsigned int const size = 32 ):
    m_size( size )
    {
    }

    ~Coke(){}

    // Coke interface
    unsigned int size() const { return m_size; }
    void size( unsigned int oz ){ m_size = oz; }

private:
    unsigned int m_size;
};

} // End namespace

#endif
