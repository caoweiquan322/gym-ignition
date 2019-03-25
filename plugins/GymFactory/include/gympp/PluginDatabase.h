/*
 * Copyright (C) 2019 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef GYMPP_PLUGINDATABASE_H
#define GYMPP_PLUGINDATABASE_H

#include "gympp/GymFactory.h"
#include "gympp/Log.h"
#include "gympp/Metadata.h"

class GymppPluginRegistrator_CartPole
{
public:
    GymppPluginRegistrator_CartPole()
    {
        auto factory = gympp::GymFactory::Instance();
        gympp::PluginMetadata cartPoleMetadata;
        gymppDebug << "Registering 'CartPole' plugin" << std::endl;

        cartPoleMetadata.setEnvironmentName("CartPole");
        cartPoleMetadata.setLibraryName("CartPolePlugin");
        cartPoleMetadata.setClassName("gympp::plugins::CartPole");
        cartPoleMetadata.setWorldFileName("CartPole.world");
        cartPoleMetadata.setModelNames({"cartpole_xacro"});

        gympp::SpaceMetadata actionSpaceMetadata;
        actionSpaceMetadata.setDimensions({3});
        actionSpaceMetadata.setType(gympp::SpaceType::Discrete);

        gympp::SpaceMetadata observationSpaceMetadata;
        observationSpaceMetadata.setType(gympp::SpaceType::Box);
        observationSpaceMetadata.setLowLimit(gympp::spaces::Box::Limit{-360, -1});
        observationSpaceMetadata.setHighLimit(gympp::spaces::Box::Limit{360, 1});

        cartPoleMetadata.setActionSpaceMetadata(actionSpaceMetadata);
        cartPoleMetadata.setObservationSpaceMetadata(observationSpaceMetadata);

        factory->registerPlugin(cartPoleMetadata);
    }
};

static GymppPluginRegistrator_CartPole plugin;

#endif // GYMPP_PLUGINDATABASE_H