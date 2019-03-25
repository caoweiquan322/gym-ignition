#ifndef GYMPP_GYMFACTORY
#define GYMPP_GYMFACTORY

#include "gympp/Environment.h"
#include "gympp/Metadata.h"
#include "gympp/Space.h"
#include <ignition/common/SingletonT.hh>

#include <string>
#include <unordered_map>
#include <vector>

namespace gympp {
    class GymFactory;
} // namespace gympp

class gympp::GymFactory : public ignition::common::SingletonT<gympp::GymFactory>
{
private:
    class Impl;
    std::unique_ptr<Impl, std::function<void(Impl*)>> pImpl;

public:
    GymFactory();

    gympp::EnvironmentPtr make(const std::string& envName);
    bool registerPlugin(const PluginMetadata& md);
};

#endif // GYMPP_GYMFACTORY
