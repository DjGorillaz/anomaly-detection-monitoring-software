#pragma once

#include <bitset>

#include <QDataStream>
#include <QDir>

#include "enums.h"

namespace AnomalyDetection::FileLib
{
    struct Config
    {
        int secondsScreen = 0; //Screenshot
        int secondsLog = 0;
        std::bitset<int(Buttons::count)> mouseButtons;
        bool logRun = false;
    };

    //Read config
    QDataStream & operator << (QDataStream& stream, Config& config);

    //Write config
    QDataStream & operator >> (QDataStream& stream, Config& config);

    bool loadConfig(Config& config, const QString& defaultPath = QDir::currentPath() + "/config.cfg");
    bool saveConfig(const Config& config, const QString& defaultPath = QDir::currentPath() + "/config.cfg");
}
