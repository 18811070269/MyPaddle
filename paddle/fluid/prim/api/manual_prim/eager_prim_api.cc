// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/fluid/eager/api/all.h"
#include "paddle/fluid/eager/api/generated/eager_generated/forwards/dygraph_functions.h"
#include "paddle/fluid/prim/api/manual_prim/prim_manual_api.h"

namespace paddle {
namespace prim {

template <>
Tensor reshape<Tensor>(const Tensor& x, const IntArray& shape) {
  VLOG(4) << "Eager Prim API reshape_ad_func call";
  return ::reshape_ad_func(x, shape);
}

template <>
Tensor full<Tensor>(const IntArray& shape,
                    const Scalar& value,
                    DataType dtype,
                    const Place& place) {
  VLOG(4) << "Eager Prim API full_ad_func call";
  return ::full_ad_func(shape, value, dtype, place);
}

template <>
std::vector<Tensor> split<Tensor>(const Tensor& x,
                                  const IntArray& sections,
                                  const Scalar& axis) {
  VLOG(4) << "Eager Prim API split_ad_func call";
  return ::split_ad_func(x, sections, axis);
}
template <>
Tensor cast<Tensor>(const Tensor& x, DataType dtype) {
  return ::cast_ad_func(x, dtype);
}
}  // namespace prim
}  // namespace paddle
