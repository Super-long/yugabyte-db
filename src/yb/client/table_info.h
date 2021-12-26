// Copyright (c) YugaByte, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
// in compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied.  See the License for the specific language governing permissions and limitations
// under the License.
//

#ifndef YB_CLIENT_TABLE_INFO_H
#define YB_CLIENT_TABLE_INFO_H

#include "yb/client/schema.h"
#include "yb/client/yb_table_name.h"

#include "yb/common/index.h"
#include "yb/common/partition.h"

#include "yb/master/master.pb.h"

namespace yb {
namespace client {

struct YBTableInfo {
  YBTableName table_name;                                       // 表名
  std::string table_id;                                         // 表的唯一ID，用于区分同名的新旧表
  YBSchema schema;                                              // schema相关的信息
  PartitionSchema partition_schema;                             // 地理分区表
  IndexMap index_map;                                           // 索引相关的信息
  boost::optional<IndexInfo> index_info;
  YBTableType table_type;                                       // 表类型相关 PG/redis/cTRANSACTION_STATUS_TABLE_TYPE
  bool colocated;                                               // 并置表相关的信息
  boost::optional<master::ReplicationInfoPB> replication_info;
};

Result<YBTableType> PBToClientTableType(TableType table_type_from_pb);
TableType ClientToPBTableType(YBTableType table_type);

}  // namespace client
}  // namespace yb

#endif  // YB_CLIENT_TABLE_INFO_H
