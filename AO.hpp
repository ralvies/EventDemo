/*------------------------------------------------------------------------------
File: AO.hpp

Description:
An active object encapsulates a distinct thread of execution that can be
customized through the use of inheritance. An AO class defines a standard
interface to start, stop and otherwise interact with a thread including its
customization through inheritance.

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
#ifndef _AO_HPP_
#define _AO_HPP_

namespace gx {

class AO
{
public:
    AO();
    virtual ~AO();

    // AO interface
    void start();

private:
    // AO interface
    virtual void run() = 0;
};

} // End namespace

#endif
