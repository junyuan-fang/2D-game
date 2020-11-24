#include "basemap.hh"

void BaseMap::initialMap(QString mapName)
{
    readCSV(mapName);

}

std::string BaseMap::getMapName()
{
    return "BaseMap";

}

QVector2D BaseMap::getGraphicsItemPosition(std::string itemName)
{
    if (itemName != ""){
        return QVector2D{0,0};
    }
    return QVector2D{0,0};
}

QVector2D BaseMap::getPlayerStartPosition() const
{
    return QVector2D{0.5*penguinStandWidth,0};
}

QVector2D BaseMap::getPlayerEndPosition() const
{
    return QVector2D{MapWidth*TileWidth-0.5*penguinStandWidth,0};
}

QVector<QVector2D> BaseMap::getEnemyPosition() const
{
    QVector<QVector2D> vec;
    return vec;
}
