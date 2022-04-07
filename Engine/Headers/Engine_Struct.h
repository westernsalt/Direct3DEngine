/*!
 * \file Engine_Struct.h
 * \date 2015/04/30 16:06
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

#ifndef Engine_Struct_h__
#define Engine_Struct_h__

namespace Engine
{
	typedef struct tagVertexColor
	{
		D3DXVECTOR3		vPos;
		DWORD			dwColor;
	}VTXCOL;
	const DWORD		VTXCOL_FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX0;


	typedef struct tagVertexTexture
	{
		D3DXVECTOR3		vPos;
		D3DXVECTOR2		vTexUV;
	}VTXTEX;
	const DWORD		VTXTEX_FVF = D3DFVF_XYZ | D3DFVF_TEX1;


	typedef struct tagVertexCube
	{
		D3DXVECTOR3		vPos;
		D3DXVECTOR3		vTex;
	}VTXCUBE;
	const DWORD		VTXFVF_CUBE = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);



	typedef struct tagIndex16
	{
		WORD			_1, _2, _3;
	}INDEX16;

	typedef struct tagIndex32
	{
		DWORD			_1, _2, _3;
	}INDEX32;

	typedef struct tagAABB
	{
		D3DXVECTOR3 m_vecMax;
		D3DXVECTOR3 m_vecMin;
	}AABB;

	typedef struct tagOBB // OBB구조체
	{
		D3DXVECTOR3 vCenterPos; // 상자 중앙의 좌표
		D3DXVECTOR3 vAxisDir[3]; //상자에 평행한 세 축의 단위벡터
		float  fAxisLen[3]; // 상자의 평행한 세 축의 길이 fAxisLen[n]은 vAxisDir[n]에 각각 대응한다.
	}OBB;
	
	typedef struct tagSphere
	{
		D3DXVECTOR3    m_vecCenter;
		float          m_fRadius;
	}SPHERE;

}

#endif // Engine_Struct_h__