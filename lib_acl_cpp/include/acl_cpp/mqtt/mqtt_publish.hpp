#pragma once

#include "mqtt_message.hpp"

namespace acl {

class ACL_CPP_API mqtt_publish : public mqtt_message {
public:
	mqtt_publish(void);
	mqtt_publish(const mqtt_header& header);
	~mqtt_publish(void);

	void set_topic(const char* topic);
	void set_pkt_id(unsigned short id);
	void set_payload(unsigned len, const char* data = NULL);


	const char* get_topic(void) const {
		return topic_.c_str();
	}

	unsigned short get_pkt_id(void) const {
		return pkt_id_;
	}

	unsigned get_payload_len(void) const {
		return payload_len_;
	}

	const string& get_payload(void) const {
		return payload_;
	}

protected:
	// @override
	bool to_string(string& out);

	// @override
	int update(const char* data, int dlen);

	// @override
	bool is_finished(void) const {
		return finished_;
	}

public:
	int update_header_var(const char* data, int dlen);
	int update_topic_len(const char* data, int dlen);
	int update_topic_val(const char* data, int dlen);
	int update_pktid(const char* data, int dlen);
	int update_payload(const char* data, int dlen);

private:
	unsigned status_;
	bool finished_;
	char buff_[2];
	int  dlen_;
	unsigned hlen_var_;

	string topic_;
	unsigned short pkt_id_;
	unsigned payload_len_;
	string payload_;
};

} // namespace acl
