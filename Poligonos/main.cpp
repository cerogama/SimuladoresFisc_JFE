#include <iostream>
#include <Box2d/Box2d.h>

int main() {

    //Definimos la gravedad
    b2Vec2 gravity(0.0f,-9.8f);

    //construimos el entorno
    b2World world(gravity);

    //hacemos el ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Le damos una forma

//declaramos una ball en una posicion y lo hacemos dinamico
    b2BodyDef BallBodyDef;
    BallBodyDef.type = b2_dynamicBody;//lo convierte en dinamico
    BallBodyDef.position.Set(0.0f, 0.0f);
    b2Body *BallBody = world.CreateBody(&BallBodyDef);


    //--------------------------------------------------------
    //Trinagle
    //declaramos la primera figura dandole un BodyDef
    b2Vec2 VertexTriangleDef[3];
    VertexTriangleDef[0].Set(0.0f,0.0f);
    VertexTriangleDef[1].Set(1.0f,0.0f);
    VertexTriangleDef[2].Set(0.0f,1.0f);

    //contador delnumero de veces asi como una definicion delque esta usando, con el set y cuantos tiene que tomar
    int32 countTriangle = 3;
    b2PolygonShape polygon1;
    polygon1.Set(VertexTriangleDef, countTriangle);

    //Le damos fixture para que tenga interaccion con el entorno(world)
    b2FixtureDef VertexTriangleFixtureDef;
    VertexTriangleFixtureDef.shape = &polygon1;
    VertexTriangleFixtureDef.density = 1.0f;
    //--------------------------------------------------------

    /*Lo mismo para las demas figurasy con ayuda de geogebra podemos sacar las posiciones
     * de cada uno de los vertices que se quieren ejecutar para dica figura*/

    //--------------------------------------------------------
    //cuadrado
    b2Vec2 VertexSquereDef[4];
    VertexSquereDef[0].Set(0.0f,0.0f);
    VertexSquereDef[1].Set(1.0f,0.0f);
    VertexSquereDef[2].Set(1.0f,1.0f);
    VertexSquereDef[3].Set(0.0f,1.0f);

    int32 countSquere = 4;
    b2PolygonShape polygon2;
    polygon2.Set(VertexSquereDef,countSquere);

    b2FixtureDef VertexSquereFixtureDef;
    VertexSquereFixtureDef.shape = &polygon2;
    VertexSquereFixtureDef.density = 1.0f;
    //--------------------------------------------------------

    //--------------------------------------------------------
    //pentagono
    b2Vec2 VertexPentagonDef[5];
    VertexPentagonDef[0].Set(1.5f,0.0f);
    VertexPentagonDef[1].Set(2.5f,0.0f);
    VertexPentagonDef[2].Set(3.0f,1.0f);
    VertexPentagonDef[3].Set(2.0f,2.0f);
    VertexPentagonDef[4].Set(1.0f,1.0f);

    int32 countPentagon = 5;
    b2PolygonShape polygon3;
    polygon3.Set(VertexPentagonDef, countPentagon);

    b2FixtureDef VertexPentagonFixtureDef;
    VertexPentagonFixtureDef.shape = &polygon3;
    VertexPentagonFixtureDef.density = 1.0f;
    //--------------------------------------------------------

    //--------------------------------------------------------
    //Exagono
    b2Vec2 VertexExagonDef[6];
    VertexExagonDef[0].Set(1.0f,0.0f);
    VertexExagonDef[1].Set(2.0f,0.0f);
    VertexExagonDef[2].Set(3.0f,1.0f);
    VertexExagonDef[3].Set(2.0f,2.0f);
    VertexExagonDef[4].Set(1.0f,2.0f);
    VertexExagonDef[5].Set(0.0f,1.0f);

    int32 countExagon = 6;
    b2PolygonShape poligon4;
    poligon4.Set(VertexExagonDef, countExagon);

    b2FixtureDef VertexExagonFixtureDef;
    VertexExagonFixtureDef.shape = &poligon4;
    VertexExagonFixtureDef.density = 1.0f;
    //--------------------------------------------------------

    //--------------------------------------------------------
    //octagono
    b2Vec2 VertexOctagonDef[8];
    VertexOctagonDef[0].Set(1.0f,0.0f);
    VertexOctagonDef[1].Set(2.0f,0.0f);
    VertexOctagonDef[2].Set(3.0f,1.0f);
    VertexOctagonDef[3].Set(3.0f,2.0f);
    VertexOctagonDef[4].Set(2.0f,3.0f);
    VertexOctagonDef[5].Set(1.0f,3.0f);
    VertexOctagonDef[6].Set(0.0f,2.0f);
    VertexOctagonDef[7].Set(0.0f,1.0f);

    int32 countOctagon = 8;
    b2PolygonShape poligon5;
    poligon5.Set(VertexOctagonDef, countOctagon);

    b2FixtureDef VertexOctagonFixtueDef;
    VertexOctagonFixtueDef.shape = &poligon5;
    VertexOctagonFixtueDef.density = 1.0f;
    //--------------------------------------------------------


}
