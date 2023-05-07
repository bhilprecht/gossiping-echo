#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "message.h"

namespace node
{
    class Node {
        private:
            size_t msg_id = 1;
            std::string name;
            std::vector<std::string> nodes;

        public:
            void handle(message::Message &m);

            size_t get_msg_id();
    };
}
