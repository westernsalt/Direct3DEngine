/*!
 * \file TerrainTex.h
 * \date 2016/06/14 10:13
 *
 * \author Administrator
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#ifndef TerrainTex_h__
#define TerrainTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CTerrainTex
	: public CVIBuffer
{
private:
	explicit CTerrainTex(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CTerrainTex(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	virtual HRESULT CreateBuffer(const WORD& wCntX, const WORD& wCntZ, const WORD& wItv);

public:
	static CTerrainTex* Create(LPDIRECT3DDEVICE9 pDevice
		, const WORD& wCntX, const WORD& wCntZ, const WORD& wItv);
};

END

#endif // TerrainTex_h__