#include "universitymap.hh"

UniversityMap::UniversityMap()
{
    initialMap(":/mapData/mapData/universityMap.csv");

}

std::string UniversityMap::getMapName()
{
    return "UniversityMap";

}

