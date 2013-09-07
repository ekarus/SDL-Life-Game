#pragma once

#include "timer.h"
#include "CApp.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CNpc.h"
#include "IGameState.h"
#include <stdlib.h>
#include <vector>

using namespace std;

class CGame: public IGameState
{
public:
    
    virtual ~CGame();

	static CGame* getInstance(){return &inst;}

	virtual bool OnInit();

	virtual void OnUpdate(float time);

	virtual void OnRender();

	virtual void OnCleanUp();

	virtual void OnPause();

	virtual void OnResume();

	virtual void Restart();

	virtual void NextLevel();

protected:

	CGame();

private:

	static CGame inst;
	CApp* app;

	CPlayer* player;
	vector<CMoveObject*> npcs;

	bool fail;
	int live_obj;
	int obj_count;
	int obj_incr;

	void AddNPC(int count);

	void ObjectsCheck();

protected:

	virtual void OnLButtonDown( int mX, int mY );

	virtual void OnLButtonUp( int mX, int mY );

	virtual void OnRButtonDown( int mX, int mY );

	virtual void OnKeyDown(SDL_Keysym key);

	virtual void OnMouseMove( int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle );

};