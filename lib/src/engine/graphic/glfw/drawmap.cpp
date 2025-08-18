//
// Created by unreaJl3x on 12.08.2025.
//
template <int w, int h>
void DrawMap(MAP<w,h> *map, bool* walk, vector<GDEFPOINT>* noisePointsP, float* noiseColor) {
    vector<char[3]>* matrix = map->GetNextChar<GLFWO_DW_DRAWDISTANCE>();
    GDEFCOLOR color(-0.1f,-0.1f,-0.1f);
    for (int i = 0; i < GLFWO_DW_DRAWDISTANCE;i++) {
        vector<GDEFPOINT> vertex;
        static bool mwall,mfloor = false;
        static float mwallCoofX,mwallCoofY, mfloorCoofx,mfloorCoofy = 1.0f;
        if (*walk) { mwallCoofX=0.7f; mwallCoofY=0.0f; mwall=true;mfloorCoofx=1.0f;mfloorCoofy=0.0f;mfloor=true; }

        CoofAddact(&mwall, &mwallCoofX, &mwallCoofY, GDEF_COOF_ADDACT);
        CoofAddact(&mfloor, &mfloorCoofx, &mfloorCoofy, GDEF_COOF_ADDACTF);

        GDEFPOINT noisePoints[2] = {GDEFPOINT(),GDEFPOINT()};*/

        //LEFT
        if ((matrix)[i][0]==GDEF_MAP_EMPTY||(matrix)[i][0]==GDEF_MAP_EMPTY_EYE) {
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.07f-GDEF_DW_LEFTCOOFX)            , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_LEFTCOOFY) , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.19f-GDEF_DW_LEFTCOOFX)            , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_LEFTCOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
            noisePoints[0] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_SX, ((vertex.end()-1)->y)-GDEF_DW_NOISE_COOF_SY);
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.32f-(GDEF_DW_LEFTCOOFX/1.72))     , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_LEFTCOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
            noisePoints[1] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_EX, (vertex.end()-1)->y);
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.25f-(GDEF_DW_LEFTCOOFX/1.72))     , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_LEFTCOOFY) , GDEF_GDEFPOINT_STATE_BOTTOM) );

            if   (i == 0  ||(i-2>-1 && (*matrix)[i][2]==GDEF_MAP_WALL) ||((i-1>-1 && (*matrix)[i][2] == GDEF_MAP_WALL ))) {
                noisePointsP->push_back(noisePoints[0]);
                noisePointsP->push_back(noisePoints[1]);
            }
        }
        else if  ((*matrix)[i][0]==GDEF_MAP_WALL) {
            vertex.push_back( GDEFPOINT( mwallCoofX* (     0.07f-GDEF_DW_LEFTCOOFX    )   , mwallCoofY* (0.47f-GDEF_DW_LEFTCOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (     0.07f-GDEF_DW_LEFTCOOFX    )   , mwallCoofY* (GDEF_WALL_HEIGHT-GDEF_DW_LEFTCOOFY)   , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* ( 0.25f-(GDEF_DW_LEFTCOOFX/1.72) )   , mwallCoofY* (GDEF_WALL_HEIGHT-GDEF_DW_LEFTCOOFY)   , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* ( 0.25f-(GDEF_DW_LEFTCOOFX/1.72) )   , mwallCoofY* (0.47f-GDEF_DW_LEFTCOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
        } else {}

        //MIDDLE
        if ((*matrix)[i][1]==GDEF_MAP_EMPTY||(*matrix)[i][1]==GDEF_MAP_EMPTY_EYE) {
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.26f-(GDEF_DW_MIDDLECOOFX))   , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_MIDDLECOOFY) ,GDEF_GDEFPOINT_STATE_BOTTOM));
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.33f-(GDEF_DW_MIDDLECOOFX))   , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_MIDDLECOOFY)  , GDEF_GDEFPOINT_STATE_TOP));
            noisePoints[0] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_SX, ((vertex.end()-1)->y)-GDEF_DW_NOISE_COOF_SY);
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.68f+(GDEF_DW_MIDDLECOOFX))   , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_MIDDLECOOFY)  , GDEF_GDEFPOINT_STATE_TOP));
            noisePoints[1] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_EX, (vertex.end()-1)->y);
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.75f+(GDEF_DW_MIDDLECOOFX))   , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_MIDDLECOOFY) , GDEF_GDEFPOINT_STATE_BOTTOM));

            if   (i == 0  ||(i-2>-1 && (*matrix)[i][2]==GDEF_MAP_WALL) ||((i-1>-1 && (*matrix)[i][2] == GDEF_MAP_WALL ))) {
                noisePointsP->push_back(noisePoints[0]);
                noisePointsP->push_back(noisePoints[1]);
            }
        }
        else if  ((*matrix)[i][1]==GDEF_MAP_WALL) {
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.26f - (GDEF_DW_MIDDLECOOFX)) , mwallCoofY* (0.47f-GDEF_DW_MIDDLECOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.26f - (GDEF_DW_MIDDLECOOFX)) , mwallCoofY* (GDEF_WALL_HEIGHT-GDEF_DW_MIDDLECOOFY)   , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.75f + (GDEF_DW_MIDDLECOOFX)) , mwallCoofY* (GDEF_WALL_HEIGHT-GDEF_DW_MIDDLECOOFY)   , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.75f + (GDEF_DW_MIDDLECOOFX)) , mwallCoofY* (0.47f-GDEF_DW_MIDDLECOOFY)  , GDEF_GDEFPOINT_STATE_TOP   ) );
        } else {}

        //RIGHT
        if ((*matrix)[i][2]==GDEF_MAP_EMPTY||(*matrix)[i][2]==GDEF_MAP_EMPTY_EYE) {
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.69f-(GDEF_DW_RIGHTCOOFX/1.72))    , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_RIGHTCOOFY)   , GDEF_GDEFPOINT_STATE_TOP   ) );
            noisePoints[0] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_SX, ((vertex.end()-1)->y)-GDEF_DW_NOISE_COOF_SY);
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.76f-(GDEF_DW_RIGHTCOOFX/1.72))    , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_RIGHTCOOFY)  , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.93f-(GDEF_DW_RIGHTCOOFX))         , (i==0? mfloorCoofy : 1 )* (0.47f-GDEF_DW_RIGHTCOOFY)  , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( (i==0? mfloorCoofx : 1 )* (0.81f-(GDEF_DW_RIGHTCOOFX))         , (i==0? mfloorCoofy : 1 )* (0.6f-GDEF_DW_RIGHTCOOFY)   , GDEF_GDEFPOINT_STATE_TOP   ) );
            noisePoints[1] = GDEFPOINT( (vertex.end()-1)->x+GDEF_DW_NOISE_COOF_EX, (vertex.end()-1)->y);

            if   (i == 0  || (i-2>-1 && (*matrix)[i][2]==GDEF_MAP_WALL) || ((i-1>-1 && (*matrix)[i][2] == GDEF_MAP_WALL ))) {
                noisePointsP->push_back(noisePoints[0]);
                noisePointsP->push_back(noisePoints[1]);
            }
        }
        else if  ((*matrix)[i][2]==GDEF_MAP_WALL) {
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.76f-(GDEF_DW_RIGHTCOOFX/1.72)     )  , mwallCoofY* (0.47f-GDEF_DW_RIGHTCOOFY )  , GDEF_GDEFPOINT_STATE_TOP   ) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.76f - (GDEF_DW_RIGHTCOOFX / 1.72) )  , mwallCoofY* (GDEF_WALL_HEIGHT - GDEF_DW_RIGHTCOOFY)  , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.93f - (GDEF_DW_RIGHTCOOFX)        )  , mwallCoofY* (GDEF_WALL_HEIGHT - GDEF_DW_RIGHTCOOFY)  , GDEF_GDEFPOINT_STATE_BOTTOM) );
            vertex.push_back( GDEFPOINT( mwallCoofX* (0.93f-(GDEF_DW_RIGHTCOOFX)          )  , mwallCoofY* (0.47f-GDEF_DW_RIGHTCOOFY )  , GDEF_GDEFPOINT_STATE_TOP   ) );
        }

       /* float *sColor = new float[3];
        color.CopyTo(sColor);
        sColor = GDEFCOLOR(sColor)+=GLFWO_DW_COLOR_COOF;
        DrawOnVertex(vertex, *walk?color.GetPColor():sColor,*walk?sColor:color.GetPColor());
        color.CopyIn(sColor);
        free(sColor);
        GDEFCOLOR(sColor).CopyTo(noiseColor);
    }
}