//
// Copyright 2020 NanoMQ Team, Inc. <jaylin@emqx.io>
//
// This software is supplied under the terms of the MIT License, a
// copy of which should be located in the distribution where this
// file was obtained (LICENSE.txt).  A copy of the license may also be
// found online at https://opensource.org/licenses/MIT.
//

#ifndef MQTT_PROTOCOL_H
#define MQTT_PROTOCOL_H

#define PROTOCOL_NAME_v31 "MQIsdp"
#define PROTOCOL_VERSION_v31 3

#define PROTOCOL_NAME "MQTT"

#define PROTOCOL_VERSION_v311 4
#define PROTOCOL_VERSION_v5 5

/* Length defination */
#define EMQ_MAX_PACKET_LEN sizeof(uint8_t)*512
#define EMQ_MAX_FIXED_HEADER_LEN sizeof(uint8_t)*5
#define EMQ_MIN_FIXED_HEADER_LEN sizeof(uint8_t)*2
#define EMQ_MIN_HEADER_LEN sizeof(uint8_t)*8
#define EMQ_CONNECT_PACKET_LEN sizeof(uint8_t)*32

/* Message types */
#define CMD_CONNECT 0x10
#define CMD_CONNACK 0x20
#define CMD_PUBLISH 0x30
#define CMD_PUBACK 0x40
#define CMD_PUBREC 0x50
#define CMD_PUBREL 0x60
#define CMD_PUBCOMP 0x70
#define CMD_SUBSCRIBE 0x80
#define CMD_SUBACK 0x90
#define CMD_UNSUBSCRIBE 0xA0
#define CMD_UNSUBACK 0xB0
#define CMD_PINGREQ 0xC0
#define CMD_PINGRESP 0xD0
#define CMD_DISCONNECT 0xE0
#define CMD_AUTH 0xF0

/* Error values */
enum err_t {
	ERR_AUTH_CONTINUE = -4,
	ERR_NO_SUBSCRIBERS = -3,
	ERR_SUB_EXISTS = -2,
	ERR_CONN_PENDING = -1,
	ERR_SUCCESS = 0,
	ERR_NOMEM = 1,
	ERR_PROTOCOL = 2,
	ERR_INVAL = 3,
	ERR_NO_CONN = 4,
	ERR_CONN_REFUSED = 5,
	ERR_NOT_FOUND = 6,
	ERR_CONN_LOST = 7,
	ERR_TLS = 8,
	ERR_PAYLOAD_SIZE = 9,
	ERR_NOT_SUPPORTED = 10,
	ERR_AUTH = 11,
	ERR_ACL_DENIED = 12,
	ERR_UNKNOWN = 13,
	ERR_ERRNO = 14,
	ERR_EAI = 15,
	ERR_PROXY = 16,
	ERR_PLUGIN_DEFER = 17,
	ERR_MALFORMED_UTF8 = 18,
	ERR_KEEPALIVE = 19,
	ERR_LOOKUP = 20,
	ERR_MALFORMED_PACKET = 21,
	ERR_DUPLICATE_PROPERTY = 22,
	ERR_TLS_HANDSHAKE = 23,
	ERR_QOS_NOT_SUPPORTED = 24,
	ERR_OVERSIZE_PACKET = 25,
	ERR_OCSP = 26,
};


typedef enum {
	SUCCESS = 0,
	NORMAL_DISCONNECTION = 0,
	GRANTED_QOS_0 = 0,
	GRANTED_QOS_1 = 1,
	GRANTED_QOS_2 = 2,
	DISCONNECT_WITH_WILL_MESSAGE = 4,
	NO_MATCHING_SUBSCRIBERS = 16,
	NO_SUBSCRIPTION_EXISTED = 17,
	CONTINUE_AUTHENTICATION = 24,
	RE_AUTHENTICATE = 25,
	UNSPECIFIED_ERROR = 128,
	MALFORMED_PACKET = 129,
	PROTOCOL_ERROR = 130,
	IMPLEMENTATION_SPECIFIC_ERROR = 131,
	UNSUPPORTED_PROTOCOL_VERSION = 132,
	CLIENT_IDENTIFIER_NOT_VALID = 133,
	BAD_USER_NAME_OR_PASSWORD = 134,
	NOT_AUTHORIZED = 135,
	SERVER_UNAVAILABLE = 136,
	SERVER_BUSY = 137,
	BANNED = 138,
	SERVER_SHUTTING_DOWN = 139,
	BAD_AUTHENTICATION_METHOD = 140,
	KEEP_ALIVE_TIMEOUT = 141,
	SESSION_TAKEN_OVER = 142,
	TOPIC_FILTER_INVALID = 143,
	TOPIC_NAME_INVALID = 144,
	PACKET_IDENTIFIER_IN_USE = 145,
	PACKET_IDENTIFIER_NOT_FOUND = 146,
	RECEIVE_MAXIMUM_EXCEEDED = 147,
	TOPIC_ALIAS_INVALID = 148,
	PACKET_TOO_LARGE = 149,
	MESSAGE_RATE_TOO_HIGH = 150,
	QUOTA_EXCEEDED = 151,
	ADMINISTRATIVE_ACTION = 152,
	PAYLOAD_FORMAT_INVALID = 153,
	RETAIN_NOT_SUPPORTED = 154,
	QOS_NOT_SUPPORTED = 155,
	USE_ANOTHER_SERVER = 156,
	SERVER_MOVED = 157,
	SHARED_SUBSCRIPTIONS_NOT_SUPPORTED = 158,
	CONNECTION_RATE_EXCEEDED = 159,
	MAXIMUM_CONNECT_TIME = 160,
	SUBSCRIPTION_IDENTIFIERS_NOT_SUPPORTED = 161,
	WILDCARD_SUBSCRIPTIONS_NOT_SUPPORTED = 162

} reason_code;

typedef enum {
	PAYLOAD_FORMAT_INDICATOR = 1,
	MESSAGE_EXPIRY_INTERVAL = 2,
	CONTENT_TYPE = 3,
	RESPONSE_TOPIC = 8,
	CORRELATION_DATA = 9,
	SUBSCRIPTION_IDENTIFIER = 11,
	SESSION_EXPIRY_INTERVAL = 17,
	ASSIGNED_CLIENT_IDENTIFIER = 18,
	SERVER_KEEP_ALIVE = 19,
	AUTHENTICATION_METHOD = 21,
	AUTHENTICATION_DATA = 22,
	REQUEST_PROBLEM_INFORMATION = 23,
	WILL_DELAY_INTERVAL = 24,
	REQUEST_RESPONSE_INFORMATION = 25,
	RESPONSE_INFORMATION = 26,
	SERVER_REFERENCE = 28,
	REASON_STRING = 31,
	RECEIVE_MAXIMUM = 33,
	TOPIC_ALIAS_MAXIMUM = 34,
	TOPIC_ALIAS = 35,
	PUBLISH_MAXIMUM_QOS = 36,
	RETAIN_AVAILABLE = 37,
	USER_PROPERTY = 38,
	MAXIMUM_PACKET_SIZE = 39,
	WILDCARD_SUBSCRIPTION_AVAILABLE = 40,
	SUBSCRIPTION_IDENTIFIER_AVAILABLE = 41,
	SHARED_SUBSCRIPTION_AVAILABLE = 42
} properties_type;

//MQTT Control Packet types
typedef enum {
	RESERVED = 0,
	CONNECT = 1,
	CONNACK = 2,
	PUBLISH = 3,
	PUBACK = 4,
	PUBREC = 5,
	PUBREL = 6,
	PUBCOMP = 7,
	SUBSCRIBE = 8,
	SUBACK = 9,
	UNSUBSCRIBE = 10,
	UNSUBACK = 11,
	PINGREQ = 12,
	PINGRESP = 13,
	DISCONNECT = 14,
	AUTH = 15
} mqtt_control_packet_types;

enum mqtt311_connack_codes {
	CONNACK_ACCEPTED = 0,
	CONNACK_REFUSED_PROTOCOL_VERSION = 1,
	CONNACK_REFUSED_IDENTIFIER_REJECTED = 2,
	CONNACK_REFUSED_SERVER_UNAVAILABLE = 3,
	CONNACK_REFUSED_BAD_USERNAME_PASSWORD = 4,
	CONNACK_REFUSED_NOT_AUTHORIZED = 5,
};


enum mqtt5_return_codes {
	MQTT_RC_SUCCESS = 0,						/* CONNACK, PUBACK, PUBREC, PUBREL, PUBCOMP, UNSUBACK, AUTH */
	MQTT_RC_NORMAL_DISCONNECTION = 0,			/* DISCONNECT */
	MQTT_RC_GRANTED_QOS0 = 0,					/* SUBACK */
	MQTT_RC_GRANTED_QOS1 = 1,					/* SUBACK */
	MQTT_RC_GRANTED_QOS2 = 2,					/* SUBACK */
	MQTT_RC_DISCONNECT_WITH_WILL_MSG = 4,		/* DISCONNECT */
	MQTT_RC_NO_MATCHING_SUBSCRIBERS = 16,		/* PUBACK, PUBREC */
	MQTT_RC_NO_SUBSCRIPTION_EXISTED = 17,		/* UNSUBACK */
	MQTT_RC_CONTINUE_AUTHENTICATION = 24,		/* AUTH */
	MQTT_RC_REAUTHENTICATE = 25,				/* AUTH */

	MQTT_RC_UNSPECIFIED = 128,					/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	MQTT_RC_MALFORMED_PACKET = 129,				/* CONNACK, DISCONNECT */
	MQTT_RC_PROTOCOL_ERROR = 130,				/* DISCONNECT */
	MQTT_RC_IMPLEMENTATION_SPECIFIC = 131,		/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	MQTT_RC_UNSUPPORTED_PROTOCOL_VERSION = 132,	/* CONNACK */
	MQTT_RC_CLIENTID_NOT_VALID = 133,			/* CONNACK */
	MQTT_RC_BAD_USERNAME_OR_PASSWORD = 134,		/* CONNACK */
	MQTT_RC_NOT_AUTHORIZED = 135,				/* CONNACK, PUBACK, PUBREC, SUBACK, UNSUBACK, DISCONNECT */
	MQTT_RC_SERVER_UNAVAILABLE = 136,			/* CONNACK */
	MQTT_RC_SERVER_BUSY = 137,					/* CONNACK, DISCONNECT */
	MQTT_RC_BANNED = 138,						/* CONNACK */
	MQTT_RC_SERVER_SHUTTING_DOWN = 139,			/* DISCONNECT */
	MQTT_RC_BAD_AUTHENTICATION_METHOD = 140,	/* CONNACK */
	MQTT_RC_KEEP_ALIVE_TIMEOUT = 141,			/* DISCONNECT */
	MQTT_RC_SESSION_TAKEN_OVER = 142,			/* DISCONNECT */
	MQTT_RC_TOPIC_FILTER_INVALID = 143,			/* SUBACK, UNSUBACK, DISCONNECT */
	MQTT_RC_TOPIC_NAME_INVALID = 144,			/* CONNACK, PUBACK, PUBREC, DISCONNECT */
	MQTT_RC_PACKET_ID_IN_USE = 145,				/* PUBACK, SUBACK, UNSUBACK */
	MQTT_RC_PACKET_ID_NOT_FOUND = 146,			/* PUBREL, PUBCOMP */
	MQTT_RC_RECEIVE_MAXIMUM_EXCEEDED = 147,		/* DISCONNECT */
	MQTT_RC_TOPIC_ALIAS_INVALID = 148,			/* DISCONNECT */
	MQTT_RC_PACKET_TOO_LARGE = 149,				/* CONNACK, PUBACK, PUBREC, DISCONNECT */
	MQTT_RC_MESSAGE_RATE_TOO_HIGH = 150,		/* DISCONNECT */
	MQTT_RC_QUOTA_EXCEEDED = 151,				/* PUBACK, PUBREC, SUBACK, DISCONNECT */
	MQTT_RC_ADMINISTRATIVE_ACTION = 152,		/* DISCONNECT */
	MQTT_RC_PAYLOAD_FORMAT_INVALID = 153,		/* CONNACK, DISCONNECT */
	MQTT_RC_RETAIN_NOT_SUPPORTED = 154,			/* CONNACK, DISCONNECT */
	MQTT_RC_QOS_NOT_SUPPORTED = 155,			/* CONNACK, DISCONNECT */
	MQTT_RC_USE_ANOTHER_SERVER = 156,			/* CONNACK, DISCONNECT */
	MQTT_RC_SERVER_MOVED = 157,					/* CONNACK, DISCONNECT */
	MQTT_RC_SHARED_SUBS_NOT_SUPPORTED = 158,	/* SUBACK, DISCONNECT */
	MQTT_RC_CONNECTION_RATE_EXCEEDED = 159,		/* CONNACK, DISCONNECT */
	MQTT_RC_MAXIMUM_CONNECT_TIME = 160,			/* DISCONNECT */
	MQTT_RC_SUBSCRIPTION_IDS_NOT_SUPPORTED = 161, /* SUBACK, DISCONNECT */
	MQTT_RC_WILDCARD_SUBS_NOT_SUPPORTED = 162,	/* SUBACK, DISCONNECT */
};

enum mqtt5_property {
	MQTT_PROP_PAYLOAD_FORMAT_INDICATOR = 1,		/* Byte :				PUBLISH, Will Properties */
	MQTT_PROP_MESSAGE_EXPIRY_INTERVAL = 2,		/* 4 byte int :			PUBLISH, Will Properties */
	MQTT_PROP_CONTENT_TYPE = 3,					/* UTF-8 string :		PUBLISH, Will Properties */
	MQTT_PROP_RESPONSE_TOPIC = 8,				/* UTF-8 string :		PUBLISH, Will Properties */
	MQTT_PROP_CORRELATION_DATA = 9,				/* Binary Data :		PUBLISH, Will Properties */
	MQTT_PROP_SUBSCRIPTION_IDENTIFIER = 11,		/* Variable byte int :	PUBLISH, SUBSCRIBE */
	MQTT_PROP_SESSION_EXPIRY_INTERVAL = 17,		/* 4 byte int :			CONNECT, CONNACK, DISCONNECT */
	MQTT_PROP_ASSIGNED_CLIENT_IDENTIFIER = 18,	/* UTF-8 string :		CONNACK */
	MQTT_PROP_SERVER_KEEP_ALIVE = 19,			/* 2 byte int :			CONNACK */
	MQTT_PROP_AUTHENTICATION_METHOD = 21,		/* UTF-8 string :		CONNECT, CONNACK, AUTH */
	MQTT_PROP_AUTHENTICATION_DATA = 22,			/* Binary Data :		CONNECT, CONNACK, AUTH */
	MQTT_PROP_REQUEST_PROBLEM_INFORMATION = 23,	/* Byte :				CONNECT */
	MQTT_PROP_WILL_DELAY_INTERVAL = 24,			/* 4 byte int :			Will properties */
	MQTT_PROP_REQUEST_RESPONSE_INFORMATION = 25,/* Byte :				CONNECT */
	MQTT_PROP_RESPONSE_INFORMATION = 26,		/* UTF-8 string :		CONNACK */
	MQTT_PROP_SERVER_REFERENCE = 28,			/* UTF-8 string :		CONNACK, DISCONNECT */
	MQTT_PROP_REASON_STRING = 31,				/* UTF-8 string :		All except Will properties */
	MQTT_PROP_RECEIVE_MAXIMUM = 33,				/* 2 byte int :			CONNECT, CONNACK */
	MQTT_PROP_TOPIC_ALIAS_MAXIMUM = 34,			/* 2 byte int :			CONNECT, CONNACK */
	MQTT_PROP_TOPIC_ALIAS = 35,					/* 2 byte int :			PUBLISH */
	MQTT_PROP_MAXIMUM_QOS = 36,					/* Byte :				CONNACK */
	MQTT_PROP_RETAIN_AVAILABLE = 37,			/* Byte :				CONNACK */
	MQTT_PROP_USER_PROPERTY = 38,				/* UTF-8 string pair :	All */
	MQTT_PROP_MAXIMUM_PACKET_SIZE = 39,			/* 4 byte int :			CONNECT, CONNACK */
	MQTT_PROP_WILDCARD_SUB_AVAILABLE = 40,		/* Byte :				CONNACK */
	MQTT_PROP_SUBSCRIPTION_ID_AVAILABLE = 41,	/* Byte :				CONNACK */
	MQTT_PROP_SHARED_SUB_AVAILABLE = 42,		/* Byte :				CONNACK */
};

enum mqtt5_property_type {
	MQTT_PROP_TYPE_BYTE = 1,
	MQTT_PROP_TYPE_INT16 = 2,
	MQTT_PROP_TYPE_INT32 = 3,
	MQTT_PROP_TYPE_VARINT = 4,
	MQTT_PROP_TYPE_BINARY = 5,
	MQTT_PROP_TYPE_STRING = 6,
	MQTT_PROP_TYPE_STRING_PAIR = 7
};

enum mqtt5_sub_options {
	MQTT_SUB_OPT_NO_LOCAL = 0x04,
	MQTT_SUB_OPT_RETAIN_AS_PUBLISHED = 0x08,
	MQTT_SUB_OPT_SEND_RETAIN_ALWAYS = 0x00,
	MQTT_SUB_OPT_SEND_RETAIN_NEW = 0x10,
	MQTT_SUB_OPT_SEND_RETAIN_NEVER = 0x20,
};

#endif
