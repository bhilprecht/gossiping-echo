#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <nlohmann/json.hpp>

using namespace nlohmann;

namespace message
{
    enum MessageType
    {
        EchoRequest,
        EchoOk,
        Init,
        InitOk,
        Invalid
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(MessageType, {
                                                  {EchoRequest, "echo"},
                                                  {EchoOk, "echo_ok"},
                                                  {Init, "init"},
                                                  {InitOk, "init_ok"},
                                                  {Invalid, nullptr},
                                              })

    class Message
    {
    private:
        std::string src;
        std::string dest;
        MessageType type;
        json body;

    public:
        Message(std::string &src, std::string &dest, MessageType type, json &body) : src(src), dest(dest), type(type), body(body){};

        static std::unique_ptr<Message> parse(std::string line);
        std::unique_ptr<Message> generate_response(MessageType& type, size_t msg_id, json &body);

        void send();

        MessageType const& get_type() const;

        json const& get_body() const;
    };
}
