/*------------------------------------------------------------------------------
File: Event.hpp

Description:
An Event is a container used to pass around event information in a more useful
and generic form than passing an event directly.

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
#ifndef _Event_HPP_
#define _Event_HPP_

#include "TypeID.hpp"

namespace gx {

class Event
{
public:
    Event(){}
    Event( unsigned int id, void *pEvent ):
    m_id( id ),
    m_pEvent( pEvent )
    {
    }

    template< class T >
    Event( T& e ):
    m_id( TypeID< T >::id() ),
    m_pEvent( &e )
    {
    }

    ~Event(){}

    // Event interface
    template< class T > inline bool instanceOf() const;
    template< class T > inline T* event();

    unsigned int getID() const { return m_id; }
    void* getEvent(){ return m_pEvent; }

private:
    unsigned int m_id;
    void *m_pEvent;
};

//------------------------------------------------------------------------------
// inline
template< class T >
bool Event::instanceOf() const
{
    return m_id == TypeID< T >::id();
}

//------------------------------------------------------------------------------
// inline
template< class T >
T* Event::event()
{
    T *pEvent = 0;
    if( instanceOf< T >() )
    {
        pEvent = static_cast< T* >( m_pEvent );
    }
    return pEvent;
}

} // End namespace

#endif
