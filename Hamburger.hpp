/*------------------------------------------------------------------------------
File: Hamburger.hpp

Description:
The Hamburger class represents an event that contains data. In this case, the
event is a hamburger object.

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
#ifndef _Hamburger_HPP_
#define _Hamburger_HPP_

namespace gx {

struct Hamburger
{
public:
    Hamburger( bool const hasKetchup = true,
               bool const hasMustard = true,
               bool const hasOnions = true,
               bool const hasPickles = false ):
    m_hasKetchup( hasKetchup ),
    m_hasMustard( hasMustard ),
    m_hasOnions( hasOnions ),
    m_hasPickles( hasPickles )
    {
    }

    ~Hamburger(){}

    // Hamburger interface
    bool hasKetchup() const { return m_hasKetchup; }
    bool hasMustard() const { return m_hasMustard; }
    bool hasOnions () const { return m_hasOnions;  }
    bool hasPickles() const { return m_hasPickles; }

    bool isPlain() const { return m_hasKetchup == false &&
                                  m_hasMustard == false &&
                                  m_hasOnions  == false &&
                                  m_hasPickles == false; }

    void makePlain()
    {
        m_hasKetchup = false;
        m_hasMustard = false;
        m_hasOnions  = false;
        m_hasPickles = false;
    }

private:
    bool m_hasKetchup;
    bool m_hasMustard;
    bool m_hasOnions;
    bool m_hasPickles;
};

} // End namespace

#endif
