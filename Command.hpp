/*------------------------------------------------------------------------------
File: Command.hpp

Description:
A Command is an interface for implementing a command using the Command Pattern.

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
#ifndef _Command_HPP_
#define _Command_HPP_

namespace gx {

class Command
{
public:
    Command(){}
    virtual ~Command(){}

    // Command interface
    virtual void execute() = 0;
};

} // End namespace

#endif
