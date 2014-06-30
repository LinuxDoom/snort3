/****************************************************************************
 *
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2003-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 ****************************************************************************/

//
//  @author     Tom Peters <thopeter@cisco.com>
//
//  @brief      NHttpMsgHeader enumerations
//

#ifndef NHTTP_ENUM_H
#define NHTTP_ENUM_H

#include <stdint.h>

#define NHTTP_GID 119

namespace NHttpEnums {

static const uint32_t MAXOCTETS = 63780;

// Field status codes for when no valid value is present in length or integer value. Positive values are actual length or field value.
typedef enum { STAT_NOTCONFIGURED=-5, STAT_NOTCOMPUTE=-4, STAT_INSUFMEMORY=-3, STAT_PROBLEMATIC=-2, STAT_NOTPRESENT=-1, STAT_EMPTYSTRING=0, STAT_OTHER=1 } StatusCode;

// Message originator--client or server
typedef enum { SRC__NOTCOMPUTE=-4, SRC_CLIENT=0, SRC_SERVER=1 } SourceId;

// Type of message section
typedef enum { SEC__NOTCOMPUTE=-4, SEC__NOTPRESENT=-1, SEC_REQUEST = 2, SEC_STATUS, SEC_HEADER, SEC_BODY, SEC_CHUNKHEAD, SEC_CHUNKBODY, SEC_TRAILER, SEC_DISCARD,
   SEC_CLOSED, SEC_ABORT } SectionType;

// List of possible HTTP versions. Version 0.9 omitted because 0.9 predates creation of the HTTP/X.Y token. There would never be a message with "HTTP/0.9"
typedef enum { VERS__NOTCOMPUTE=-4, VERS__PROBLEMATIC=-2, VERS__NOTPRESENT=-1, VERS__OTHER=1, VERS_1_0, VERS_1_1, VERS_2_0 } VersionId;

// Every request method we have ever heard of
typedef enum { METH__NOTCOMPUTE=-4, METH__INSUFMEMORY=-3, METH__PROBLEMATIC=-2, METH__NOTPRESENT=-1, METH__OTHER=1, METH_OPTIONS, METH_GET, METH_HEAD, METH_POST, METH_PUT,
   METH_DELETE, METH_TRACE, METH_CONNECT, METH_PROPFIND,
   METH_PROPPATCH, METH_MKCOL, METH_COPY, METH_MOVE, METH_LOCK, METH_UNLOCK, METH_VERSION_CONTROL, METH_REPORT, METH_CHECKOUT, METH_CHECKIN, METH_UNCHECKOUT,
   METH_MKWORKSPACE, METH_UPDATE, METH_LABEL, METH_MERGE, METH_BASELINE_CONTROL, METH_MKACTIVITY, METH_ORDERPATCH, METH_ACL, METH_PATCH, METH_SEARCH, METH_BCOPY,
   METH_BDELETE, METH_BMOVE, METH_BPROPFIND, METH_BPROPPATCH, METH_NOTIFY, METH_POLL, METH_SUBSCRIBE, METH_UNSUBSCRIBE, METH_X_MS_ENUMATTS, METH_BIND, METH_LINK,
   METH_MKCALENDAR, METH_MKREDIRECTREF, METH_REBIND, METH_UNBIND, METH_UNLINK, METH_UPDATEREDIRECTREF } MethodId;

// URI formats
typedef enum { URI__NOTCOMPUTE=-4, URI__PROBLEMATIC=-2, URI__NOTPRESENT=-1, URI_ASTERISK = 2, URI_AUTHORITY, URI_ABSPATH, URI_ABSOLUTE } UriType;

// URI schemes
typedef enum { SCH__NOTCOMPUTE=-4, SCH__INSUFMEMORY=-3, SCH__NOTPRESENT=-1, SCH_OTHER = 1, SCH_HTTP, SCH_HTTPS, SCH_FTP, SCH_GOPHER, SCH_FILE } SchemeId;

// Every header we have ever heard of
typedef enum { HEAD__NOTCOMPUTE=-4, HEAD__INSUFMEMORY=-3, HEAD__PROBLEMATIC=-2, HEAD__NOTPRESENT=-1, HEAD__OTHER=1, HEAD_CACHE_CONTROL, HEAD_CONNECTION, HEAD_DATE,
   HEAD_PRAGMA, HEAD_TRAILER, HEAD_COOKIE, HEAD_SET_COOKIE,
   HEAD_TRANSFER_ENCODING, HEAD_UPGRADE, HEAD_VIA, HEAD_WARNING, HEAD_ACCEPT, HEAD_ACCEPT_CHARSET, HEAD_ACCEPT_ENCODING, HEAD_ACCEPT_LANGUAGE, HEAD_AUTHORIZATION,
   HEAD_EXPECT, HEAD_FROM, HEAD_HOST, HEAD_IF_MATCH, HEAD_IF_MODIFIED_SINCE, HEAD_IF_NONE_MATCH, HEAD_IF_RANGE, HEAD_IF_UNMODIFIED_SINCE, HEAD_MAX_FORWARDS,
   HEAD_PROXY_AUTHORIZATION, HEAD_RANGE, HEAD_REFERER, HEAD_TE, HEAD_USER_AGENT, HEAD_ACCEPT_RANGES, HEAD_AGE, HEAD_ETAG, HEAD_LOCATION, HEAD_PROXY_AUTHENTICATE,
   HEAD_RETRY_AFTER, HEAD_SERVER, HEAD_VARY, HEAD_WWW_AUTHENTICATE, HEAD_ALLOW, HEAD_CONTENT_ENCODING, HEAD_CONTENT_LANGUAGE, HEAD_CONTENT_LENGTH,
   HEAD_CONTENT_LOCATION, HEAD_CONTENT_MD5, HEAD_CONTENT_RANGE, HEAD_CONTENT_TYPE, HEAD_EXPIRES, HEAD_LAST_MODIFIED, HEAD__MAXVALUE } HeaderId;

// All the infractions we might find while parsing and analyzing a message
typedef enum {
   INF_TRUNCATED=0x1, INF_HEADTOOLONG=0x2, INF_BADREQLINE=0x4, INF_BADSTATLINE=0x8, INF_TOOMANYHEADERS=0x10,
   INF_BADHEADER=0x20, INF_BADSTATCODE=0x40, INF_UNKNOWNVERSION=0x80, INF_BADVERSION=0x100, INF_NOSCRATCH=0x200,
   INF_BADHEADERREPS=0x400, INF_BADHEADERDATA=0x800, INF_BROKENCHUNK=0x1000, INF_BADCHUNKSIZE=0x2000,
   INF_BADPHRASE=0x4000, INF_BADURI=0x8000, INF_BADPORT=0x10000, INF_URINEEDNORM=0x20000, INF_URIPERCENTNORMAL=0x40000,
   INF_URIPERCENTASCII=0x80000, INF_URIPERCENTUTF8=0x100000, INF_URIPERCENTUCODE=0x200000, INF_URIPERCENTOTHER=0x400000,
   INF_URIBADCHAR=0x800000, INF_URI8BITCHAR=0x1000000, INF_URIMULTISLASH=0x2000000, INF_URIBACKSLASH=0x4000000,
   INF_URISLASHDOT=0x8000000, INF_URISLASHDOTDOT=0x10000000, INF_URIROOTTRAV=0x20000000 } Infraction;

// Formats for output from a header normalization function
typedef enum { NORM_NULL, NORM_FIELD, NORM_INT64, NORM_ENUM64, NORM_ENUM64LIST } NormFormat;

// Types of character for URI scanning
typedef enum { CHAR_NORMAL=2, CHAR_PERCENT, CHAR_SLASH, CHAR_BACKSLASH, CHAR_PERIOD, CHAR_INVALID, CHAR_EIGHTBIT } CharAction;

// Transfer codings
typedef enum { TRANSCODE__OTHER=1, TRANSCODE_CHUNKED, TRANSCODE_IDENTITY, TRANSCODE_GZIP, TRANSCODE_COMPRESS, TRANSCODE_DEFLATE } Transcoding;

} // end namespace NHttpEnums

// Individual pieces of the message found during parsing
// Length values <= 0 are StatusCode values and imply that the start pointer is meaningless.
// Never use the start pointer without verifying that length > 0.
struct field {
public:
    const uint8_t *start;
    int32_t length;
};

typedef enum 
{
    EVENT_ASCII = 1,
    EVENT_DOUBLE_DECODE, 
    EVENT_U_ENCODE, 
    EVENT_BARE_BYTE, 
    EVENT_OBSOLETE_1,
    EVENT_UTF_8, 
    EVENT_IIS_UNICODE, 
    EVENT_MULTI_SLASH, 
    EVENT_IIS_BACKSLASH, 
    EVENT_SELF_DIR_TRAV, 
    EVENT_DIR_TRAV,
    EVENT_APACHE_WS,
    EVENT_IIS_DELIMITER,
    EVENT_NON_RFC_CHAR,
    EVENT_OVERSIZE_DIR,
    EVENT_LARGE_CHUNK,
    EVENT_PROXY_USE,
    EVENT_WEBROOT_DIR,
    EVENT_LONG_HDR,
    EVENT_MAX_HEADERS,
    EVENT_MULTIPLE_CONTLEN,
    EVENT_CHUNK_SIZE_MISMATCH,
    EVENT_INVALID_TRUEIP,
    EVENT_MULTIPLE_HOST_HDRS,
    EVENT_LONG_HOSTNAME,
    EVENT_EXCEEDS_SPACES,
    EVENT_CONSECUTIVE_SMALL_CHUNKS,
    EVENT_UNBOUNDED_POST,
    EVENT_MULTIPLE_TRUEIP_IN_SESSION,
    EVENT_BOTH_TRUEIP_XFF_HDRS,
    EVENT_UNKNOWN_METHOD,
    EVENT_SIMPLE_REQUEST,
    EVENT_UNESCAPED_SPACE_URI,
    EVENT_PIPELINE_MAX,
    EVENT_ANOM_SERVER,
    EVENT_INVALID_STATCODE,
    EVENT_NO_CONTLEN,
    EVENT_UTF_NORM_FAIL,
    EVENT_UTF7,
    EVENT_DECOMPR_FAILED,
    EVENT_CONSECUTIVE_SMALL_CHUNKS_S,
    EVENT_MSG_SIZE_EXCEPTION,
    EVENT_JS_OBFUSCATION_EXCD,
    EVENT_JS_EXCESS_WS,
    EVENT_MIXED_ENCODINGS,
    EVENT_MAXVALUE
} EventSid;

#endif

