#include "node.h"
#include <utility>

namespace node
{
    void Node::handle(message::Message &m)
    {
        json body = m.get_body();
        switch (m.get_type())
        {
        case message::MessageType::Init:
        {
            json body_resp = {};
            auto type = message::MessageType::InitOk;
            auto m_resp = m.generate_response(type, get_msg_id(), body_resp);
            m_resp->send();

            break;
        }
        case message::MessageType::InitOk:
        {
            // ignored
            break;
        }
        case message::MessageType::EchoRequest:
        {
            json body_resp = {
                {"echo", body["echo"]},
            };
            auto type = message::MessageType::EchoOk;
            auto m_resp = m.generate_response(type, get_msg_id(), body_resp);
            m_resp->send();

            break;
        }
        case message::MessageType::EchoOk:
        {
            // ignored
            break;
        }
        case message::MessageType::Invalid:
        {
            // ignored
            break;
        }
        }
    }

    size_t Node::get_msg_id()
    {
        return msg_id++;
    }
}
