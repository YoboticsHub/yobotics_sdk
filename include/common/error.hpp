#ifndef __YBT_ERROR_HPP__
#define __YBT_ERROR_HPP__

#include <decl.hpp>

namespace yobotics
{
//Declare error
YBT_DECL_ERR(YBT_OK,              0,      "Success")
YBT_DECL_ERR(YBT_ERR_COMMON,      1001,   "common error")
YBT_DECL_ERR(YBT_ERR_NETWORK,     1011,   "Network error")
YBT_DECL_ERR(YBT_ERR_TIMEOUT,     1012,   "Timeout error")
YBT_DECL_ERR(YBT_ERR_UNKNOWN,     -1,     "Unknown error")

}

#endif//__YBT_ERROR_HPP__
    