/*!
 * \file CubeColor.h
 * \date 2016/06/28 10:11
 *
 * \author USER
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/

#ifndef CubeColor_h__
#define CubeColor_h__


#include "VIBuffer.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CCubeColor
	: public CVIBuffer
{
private:
	explicit CCubeColor(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CCubeColor(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	virtual HRESULT CreateBuffer(void);

public:
	static CCubeColor* Create(LPDIRECT3DDEVICE9 pDevice);
};

END



#endif // CubeColor_h__