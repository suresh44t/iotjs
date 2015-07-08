/* Copyright 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "iotjs_exception.h"

#include <stdio.h>

#include "uv.h"


namespace iotjs {


JObject CreateUVException(int errorno, const jschar* syscall) {
    static char msg[256];
    snprintf(msg, sizeof(msg),
             "'%s' %s",
             reinterpret_cast<const char*>(syscall),
             uv_strerror(errorno));
    return JObject::Error(JSCT(msg));
}


} // namespace iotjs