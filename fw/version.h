/*
	Copyright 2025 Efabless Corp.

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

#ifndef EF_VERSION_H
#define EF_VERSION_H

#include <stdint.h>             // standard integer definition provided by the compiler

// Driver version structure
typedef struct _DRIVER_VERSION {
  uint16_t api;     ///<  Refers to the version of the Application Programming  Interface that the driver implements. 
                    ///<  This ensures compatibility with the system or application using it.
  uint16_t drv;     ///<  Refers to the specific version of the driver implementation, useful for debugging, updates, and compatibility checks.
} DRIVER_VERSION;

#endif
