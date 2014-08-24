/*------------------------------------------------------------------------------
File: TypeID.cpp

Description:
The TypeID class is used to return a unique ID for any given type.
The TypeIDGenerator class is used to generate a unique ID for any given type.

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
#include "TypeID.hpp"

using namespace gx;

//------------------------------------------------------------------------------
unsigned int TypeIDGenerator::generateID()
{
    static unsigned int nextID = 100;
    return nextID++;
}
