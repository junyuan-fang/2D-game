#include "airportmap.hh"

AirportsMap::AirportsMap()
{
    initialMap(":/mapData/mapData/airportsMap.csv");
    // add enemy position
    enemyPosition.append({45*TileWidth,21*TileHeight-0.5*enemyHeight});
    enemyPosition.append({61*TileWidth, 21*TileHeight-0.5*enemyHeight});
}

std::string AirportsMap::getMapName()
{
    return "AirportsMap";
}
