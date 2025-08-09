//-----------------------------------------------------------------------------
// File : d3dx9math_wrapper.cpp
// Desc : Wrapper for d3dx9math
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "d3dx9math_wrapper.h"


///////////////////////////////////////////////////////////////////////////////
// Float16
///////////////////////////////////////////////////////////////////////////////

// Converts an array 32-bit floats to 16-bit floats
D3DXFLOAT16* WRAP_API D3DXFloat32To16Array
    ( D3DXFLOAT16 *pOut, const float *pIn, uint32_t n )
{
    assert(pOut != nullptr);
    assert(pIn  != nullptr);
    for(auto i=0; i<n; ++i)
    {
        pOut[i] = DirectX::PackedVector::XMConvertFloatToHalf(pIn[i]);
    }
    return pOut;
}

// Converts an array 16-bit floats to 32-bit floats
float* WRAP_API D3DXFloat16To32Array
    ( float *pOut, const D3DXFLOAT16 *pIn, uint32_t n )
{
    assert(pOut != nullptr);
    assert(pIn  != nullptr);
    for(auto i=0; i<n; ++i)
    {
        pOut[i] = DirectX::PackedVector::XMConvertHalfToFloat(pIn[i]);
    }
    return pOut;
}

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2
///////////////////////////////////////////////////////////////////////////////

D3DXVECTOR2* WRAP_API D3DXVec2Normalize
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV )
{
    auto v   = DirectX::XMLoadFloat2(pV);
    auto ret = DirectX::XMVector2Normalize(v);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR2* WRAP_API D3DXVec2Hermite
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pT1,
      const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pT2, float s )
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pT1  != nullptr);
    assert(pV2  != nullptr);
    assert(pT2  != nullptr);

    auto v1  = DirectX::XMLoadFloat2(pV1);
    auto t1  = DirectX::XMLoadFloat2(pT1);
    auto v2  = DirectX::XMLoadFloat2(pV2);
    auto t2  = DirectX::XMLoadFloat2(pT2);
    auto vs  = DirectX::XMVectorSet(s, s, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR2* WRAP_API D3DXVec2CatmullRom
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV0, const D3DXVECTOR2 *pV1,
      const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pV3, float s )
{
    assert(pOut != nullptr);
    assert(pV0  != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v0 = DirectX::XMLoadFloat2(pV0);
    auto v1 = DirectX::XMLoadFloat2(pV1);
    auto v2 = DirectX::XMLoadFloat2(pV2);
    auto v3 = DirectX::XMLoadFloat2(pV3);
    auto vs = DirectX::XMVectorSet(s, s, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR2* WRAP_API D3DXVec2BaryCentric
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pV2,
      const D3DXVECTOR2 *pV3, float f, float g)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat2(pV1);
    auto v2  = DirectX::XMLoadFloat2(pV2);
    auto v3  = DirectX::XMLoadFloat2(pV3);
    auto vf  = DirectX::XMVectorSet(f, f, 0.0f, 0.0f);
    auto vg  = DirectX::XMVectorSet(g, g, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoord
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2TransformCoord(vec, mat);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormal
    ( D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV, const D3DXMATRIX *pM )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2TransformNormal(vec, mat);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}
     
// Transform Array (x, y, 0, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec2TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WRAP_API D3DXVec2TransformCoordArray
    ( D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformCoordStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, 0, 0) by matrix.
D3DXVECTOR2* WRAP_API D3DXVec2TransformNormalArray
    ( D3DXVECTOR2 *pOut, uint32_t OutStride, const D3DXVECTOR2 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformNormalStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3
///////////////////////////////////////////////////////////////////////////////

D3DXVECTOR3* WRAP_API D3DXVec3Normalize
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV )
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto ret = DirectX::XMVector3Normalize(vec);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR3* WRAP_API D3DXVec3Hermite
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pT1,
      const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pT2, float s )
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pT1  != nullptr);
    assert(pV2  != nullptr);

    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto t1  = DirectX::XMLoadFloat3(pT1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto t2  = DirectX::XMLoadFloat3(pT2);
    auto vs  = DirectX::XMVectorSet(s, s, s, 0.0f);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR3* WRAP_API D3DXVec3CatmullRom
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV0, const D3DXVECTOR3 *pV1,
      const D3DXVECTOR3 *pV2, const D3DXVECTOR3 *pV3, float s )
{
    auto v0 = DirectX::XMLoadFloat3(pV0);
    auto v1 = DirectX::XMLoadFloat3(pV1);
    auto v2 = DirectX::XMLoadFloat3(pV2);
    auto v3 = DirectX::XMLoadFloat3(pV3);
    auto vs = DirectX::XMVectorSet(s, s, s, 0.0f);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR3* WRAP_API D3DXVec3BaryCentric
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
      const D3DXVECTOR3 *pV3, float f, float g)
{
    auto v1 = DirectX::XMLoadFloat3(pV1);
    auto v2 = DirectX::XMLoadFloat3(pV2);
    auto v3 = DirectX::XMLoadFloat3(pV3);
    auto vf = DirectX::XMVectorSet(f, f, f, 0.0f);
    auto vg = DirectX::XMVectorSet(g, g, g, 0.0f);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 1) by matrix.
D3DXVECTOR4* WRAP_API D3DXVec3Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM )
{
    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoord
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM )
{
    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3TransformCoord(vec, mat);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormal
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DXMATRIX *pM )
{
    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3TransformNormal(vec, mat);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform Array (x, y, z, 1) by matrix. 
D3DXVECTOR4* WRAP_API D3DXVec3TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WRAP_API D3DXVec3TransformCoordArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformCoordStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WRAP_API D3DXVec3TransformNormalArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformNormalStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Project vector from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3Project
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld)
{
    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto vec   = DirectX::XMLoadFloat3(pV);
    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);
    auto ret   = DirectX::XMVector3Project(vec, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Project vector from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3Unproject
    ( D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld)
{
    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto proj = DirectX::XMLoadFloat4x4(pProjection);
    auto view = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);
    auto ret = DirectX::XMVector3Unproject(vec, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}
      
// Project vector Array from object space into screen space
D3DXVECTOR3* WRAP_API D3DXVec3ProjectArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride,const D3DXVECTOR3 *pV, uint32_t VStride,const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n)
{
    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);

    DirectX::XMVector3ProjectStream(pOut, OutStride, pV, VStride, n, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    return pOut;
}

// Project vector Array from screen space into object space
D3DXVECTOR3* WRAP_API D3DXVec3UnprojectArray
    ( D3DXVECTOR3 *pOut, uint32_t OutStride, const D3DXVECTOR3 *pV, uint32_t VStride, const D3DVIEWPORT9 *pViewport,
      const D3DXMATRIX *pProjection, const D3DXMATRIX *pView, const D3DXMATRIX *pWorld, uint32_t n)
{
    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto proj = DirectX::XMLoadFloat4x4(pProjection);
    auto view = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);

    DirectX::XMVector3UnprojectStream(pOut, OutStride, pV, VStride, n, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4
///////////////////////////////////////////////////////////////////////////////

// Cross-product in 4 dimensions.
D3DXVECTOR4* WRAP_API D3DXVec4Cross
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
      const D3DXVECTOR4 *pV3)
{
    auto v1 = DirectX::XMLoadFloat4(pV1);
    auto v2 = DirectX::XMLoadFloat4(pV2);
    auto v3 = DirectX::XMLoadFloat4(pV3);
    auto ret = DirectX::XMVector4Cross(v1, v2, v3);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

D3DXVECTOR4* WRAP_API D3DXVec4Normalize
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV )
{
    auto vec = DirectX::XMLoadFloat4(pV);
    auto ret = DirectX::XMVector4Normalize(vec);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* WRAP_API D3DXVec4Hermite
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pT1,
      const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pT2, float s )
{
    auto v1 = DirectX::XMLoadFloat4(pV1);
    auto t1 = DirectX::XMLoadFloat4(pT1);
    auto v2 = DirectX::XMLoadFloat4(pV2);
    auto t2 = DirectX::XMLoadFloat4(pT2);
    auto vs = DirectX::XMVectorSet(s, s, s, s);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* WRAP_API D3DXVec4CatmullRom
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV0, const D3DXVECTOR4 *pV1,
      const D3DXVECTOR4 *pV2, const D3DXVECTOR4 *pV3, float s )
{
    auto v0 = DirectX::XMLoadFloat4(pV0);
    auto v1 = DirectX::XMLoadFloat4(pV1);
    auto v2 = DirectX::XMLoadFloat4(pV2);
    auto v3 = DirectX::XMLoadFloat4(pV3);
    auto vs = DirectX::XMVectorSet(s, s, s, s);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* WRAP_API D3DXVec4BaryCentric
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV1, const D3DXVECTOR4 *pV2,
      const D3DXVECTOR4 *pV3, float f, float g)
{
    auto v1 = DirectX::XMLoadFloat4(pV1);
    auto v2 = DirectX::XMLoadFloat4(pV2);
    auto v3 = DirectX::XMLoadFloat4(pV3);
    auto vf = DirectX::XMVectorSet(f, f, f, f);
    auto vg = DirectX::XMVectorSet(g, g, g, g);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform vector by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4Transform
    ( D3DXVECTOR4 *pOut, const D3DXVECTOR4 *pV, const D3DXMATRIX *pM )
{
    auto vec = DirectX::XMLoadFloat4(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector4Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}
    
// Transform vector array by matrix.
D3DXVECTOR4* WRAP_API D3DXVec4TransformArray
    ( D3DXVECTOR4 *pOut, uint32_t OutStride, const D3DXVECTOR4 *pV, uint32_t VStride, const D3DXMATRIX *pM, uint32_t n )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector4TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXMATRIX
///////////////////////////////////////////////////////////////////////////////

float WRAP_API D3DXMatrixDeterminant
    ( const D3DXMATRIX *pM )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixDeterminant(mat);
    return DirectX::XMVectorGetX(ret);
}

long WRAP_API D3DXMatrixDecompose
    ( D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, 
	  D3DXVECTOR3 *pOutTranslation, const D3DXMATRIX *pM )
{
    DirectX::XMVECTOR scale;
    DirectX::XMVECTOR rotate;
    DirectX::XMVECTOR translation;
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixDecompose(&scale, &rotate, &translation, mat);
    if (!ret)
    {
        return -2005530516;// D3DERR_INVALIDCALL
    }

    DirectX::XMStoreFloat3(pOutScale, scale);
    DirectX::XMStoreFloat4(pOutRotation, rotate);
    DirectX::XMStoreFloat3(pOutTranslation, translation);

    return 0; // S_OK.
}

D3DXMATRIX* WRAP_API D3DXMatrixTranspose
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM )
{
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixTranspose(mat);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* WRAP_API D3DXMatrixMultiply
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2 )
{
    auto m1 = DirectX::XMLoadFloat4x4(pM1);
    auto m2 = DirectX::XMLoadFloat4x4(pM2);
    auto ret = DirectX::XMMatrixMultiply(m1, m2);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* WRAP_API D3DXMatrixMultiplyTranspose
    ( D3DXMATRIX *pOut, const D3DXMATRIX *pM1, const D3DXMATRIX *pM2 )
{
    auto m1 = DirectX::XMLoadFloat4x4(pM1);
    auto m2 = DirectX::XMLoadFloat4x4(pM2);
    auto ret = DirectX::XMMatrixMultiplyTranspose(m1, m2);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* WRAP_API D3DXMatrixInverse
    ( D3DXMATRIX *pOut, float *pDeterminant, const D3DXMATRIX *pM )
{
    DirectX::XMVECTOR det;
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixInverse(&det, mat);
    DirectX::XMStoreFloat(pDeterminant, det);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* WRAP_API D3DXMatrixScaling
    ( D3DXMATRIX *pOut, float sx, float sy, float sz )
{
    auto ret = DirectX::XMMatrixScaling(sx, sy, sz);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WRAP_API D3DXMatrixTranslation
    ( D3DXMATRIX *pOut, float x, float y, float z )
{
    auto ret = DirectX::XMMatrixTranslation(x, y, z);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the X axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationX
    ( D3DXMATRIX *pOut, float Angle )
{
    auto ret = DirectX::XMMatrixRotationX(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the Y axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationY
    ( D3DXMATRIX *pOut, float Angle )
{
    auto ret = DirectX::XMMatrixRotationY(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the Z axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationZ
    ( D3DXMATRIX *pOut, float Angle )
{
    auto ret = DirectX::XMMatrixRotationZ(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around an arbitrary axis
D3DXMATRIX* WRAP_API D3DXMatrixRotationAxis
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pV, float Angle )
{
    auto axis = DirectX::XMLoadFloat3(pV);
    auto ret = DirectX::XMMatrixRotationAxis(axis, Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix from a quaternion
D3DXMATRIX* WRAP_API D3DXMatrixRotationQuaternion
    ( D3DXMATRIX *pOut, const D3DXQUATERNION *pQ)
{
    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret = DirectX::XMMatrixRotationQuaternion(quat);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXMATRIX* WRAP_API D3DXMatrixRotationYawPitchRoll
    ( D3DXMATRIX *pOut, float Yaw, float Pitch, float Roll )
{
    auto ret = DirectX::XMMatrixRotationRollPitchYaw(Pitch, Yaw, Roll);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build transformation matrix.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pScalingCenter,
      const D3DXQUATERNION *pScalingRotation, const D3DXVECTOR3 *pScaling,
      const D3DXVECTOR3 *pRotationCenter, const D3DXQUATERNION *pRotation,
      const D3DXVECTOR3 *pTranslation)
{
    auto scalingCenter = DirectX::XMLoadFloat3(pScalingCenter);
    auto scalingRotation = DirectX::XMLoadFloat4(pScalingRotation);
    auto scaling = DirectX::XMLoadFloat3(pScaling);
    auto rotationCenter = DirectX::XMLoadFloat3(pRotationCenter);
    auto rotation = DirectX::XMLoadFloat4(pRotation);
    auto translation = DirectX::XMLoadFloat3(pTranslation);
    auto ret = DirectX::XMMatrixTransformation(scalingCenter, scalingRotation, scaling, rotationCenter, rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixTransformation2D
    ( D3DXMATRIX *pOut, const D3DXVECTOR2* pScalingCenter, 
      float ScalingRotation, const D3DXVECTOR2* pScaling, 
      const D3DXVECTOR2* pRotationCenter, float Rotation, 
      const D3DXVECTOR2* pTranslation)
{
    auto scalingCenter = DirectX::XMLoadFloat2(pScalingCenter);
    auto scaling = DirectX::XMLoadFloat2(pScaling);
    auto rotationCenter = DirectX::XMLoadFloat2(pRotationCenter);
    auto translation = DirectX::XMLoadFloat2(pTranslation);
    auto ret = DirectX::XMMatrixTransformation2D(scalingCenter, ScalingRotation, scaling, rotationCenter, Rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build affine transformation matrix.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation
    ( D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR3 *pRotationCenter,
      const D3DXQUATERNION *pRotation, const D3DXVECTOR3 *pTranslation)
{
    auto scaling = DirectX::XMVectorSet(Scaling, Scaling, Scaling, 1.0f);
    auto rotationCenter = DirectX::XMLoadFloat3(pRotationCenter);
    auto rotation = DirectX::XMLoadFloat4(pRotation);
    auto translation = DirectX::XMLoadFloat3(pTranslation);
    auto ret = DirectX::XMMatrixAffineTransformation(scaling, rotationCenter, rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WRAP_API D3DXMatrixAffineTransformation2D
    ( D3DXMATRIX *pOut, float Scaling, const D3DXVECTOR2* pRotationCenter, 
      float Rotation, const D3DXVECTOR2* pTranslation)
{
    auto scaling = DirectX::XMVectorSet(Scaling, Scaling, 1.0f, 1.0f);
    auto rotationCenter = DirectX::XMLoadFloat2(pRotationCenter);
    auto translation = DirectX::XMLoadFloat2(pTranslation);
    auto ret = DirectX::XMMatrixAffineTransformation2D(scaling, rotationCenter, Rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a lookat matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtRH
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt,
      const D3DXVECTOR3 *pUp )
{
    auto eye = DirectX::XMLoadFloat3(pEye);
    auto at  = DirectX::XMLoadFloat3(pAt);
    auto up  = DirectX::XMLoadFloat3(pUp);
    auto ret = DirectX::XMMatrixLookAtRH(eye, at, up);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a lookat matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixLookAtLH
    ( D3DXMATRIX *pOut, const D3DXVECTOR3 *pEye, const D3DXVECTOR3 *pAt,
      const D3DXVECTOR3 *pUp )
{
    auto eye = DirectX::XMLoadFloat3(pEye);
    auto at  = DirectX::XMLoadFloat3(pAt);
    auto up  = DirectX::XMLoadFloat3(pUp);
    auto ret = DirectX::XMMatrixLookAtLH(eye, at, up);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveRH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf )
{
    auto ret = DirectX::XMMatrixPerspectiveRH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveLH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf )
{
    auto ret = DirectX::XMMatrixPerspectiveLH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovRH
    ( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf )
{
    auto ret = DirectX::XMMatrixPerspectiveFovRH(fovy, Aspect, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, float fovy, float Aspect, float zn, float zf )
{
    auto ret = DirectX::XMMatrixPerspectiveFovLH(fovy, Aspect, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterRH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf )
{
    auto ret = DirectX::XMMatrixPerspectiveOffCenterRH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixPerspectiveOffCenterLH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf )
{
    auto ret = DirectX::XMMatrixOrthographicOffCenterLH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoRH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf )
{
    auto ret = DirectX::XMMatrixOrthographicRH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoLH
    ( D3DXMATRIX *pOut, float w, float h, float zn, float zf )
{
    auto ret = DirectX::XMMatrixOrthographicLH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterRH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf )
{
    auto ret = DirectX::XMMatrixOrthographicOffCenterRH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WRAP_API D3DXMatrixOrthoOffCenterLH
    ( D3DXMATRIX *pOut, float l, float r, float b, float t, float zn,
      float zf )
{
    auto ret = DirectX::XMMatrixOrthographicOffCenterLH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which flattens geometry into a plane, as if casting
// a shadow from a light.
D3DXMATRIX* WRAP_API D3DXMatrixShadow
    ( D3DXMATRIX *pOut, const D3DXVECTOR4 *pLight,
      const D3DXPLANE *pPlane )
{
    auto plane = DirectX::XMVectorSet(pPlane->a, pPlane->b, pPlane->c, pPlane->d);
    auto light = DirectX::XMLoadFloat4(pLight);
    auto ret = DirectX::XMMatrixShadow(plane, light);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which reflects the coordinate system about a plane
D3DXMATRIX* WRAP_API D3DXMatrixReflect
    ( D3DXMATRIX *pOut, const D3DXPLANE *pPlane )
{
    auto plane = DirectX::XMVectorSet(pPlane->a, pPlane->b, pPlane->c, pPlane->d);
    auto ret = DirectX::XMMatrixReflect(plane);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

///////////////////////////////////////////////////////////////////////////////
// D3DXQUATERNION
///////////////////////////////////////////////////////////////////////////////

// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
void WRAP_API D3DXQuaternionToAxisAngle
    ( const D3DXQUATERNION *pQ, D3DXVECTOR3 *pAxis, float *pAngle );

// Build a quaternion from a rotation matrix.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationMatrix
    ( D3DXQUATERNION *pOut, const D3DXMATRIX *pM);

// Rotation about arbitrary axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationAxis
    ( D3DXQUATERNION *pOut, const D3DXVECTOR3 *pV, float Angle );

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXQUATERNION* WRAP_API D3DXQuaternionRotationYawPitchRoll
    ( D3DXQUATERNION *pOut, float Yaw, float Pitch, float Roll );

// Quaternion multiplication.  The result represents the rotation Q2
// followed by the rotation Q1.  (Out = Q2 * Q1)
D3DXQUATERNION* WRAP_API D3DXQuaternionMultiply
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2 );

D3DXQUATERNION* WRAP_API D3DXQuaternionNormalize
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Conjugate and re-norm
D3DXQUATERNION* WRAP_API D3DXQuaternionInverse
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionLn
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)
D3DXQUATERNION* WRAP_API D3DXQuaternionExp
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ );
      
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
// Expects unit quaternions.
D3DXQUATERNION* WRAP_API D3DXQuaternionSlerp
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2, float t );

// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))
D3DXQUATERNION* WRAP_API D3DXQuaternionSquad
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pA, const D3DXQUATERNION *pB,
      const D3DXQUATERNION *pC, float t );

// Setup control points for spherical quadrangle interpolation
// from Q1 to Q2.  The control points are chosen in such a way 
// to ensure the continuity of tangents with adjacent segments.
void WRAP_API D3DXQuaternionSquadSetup
    ( D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut,
      const D3DXQUATERNION *pQ0, const D3DXQUATERNION *pQ1, 
      const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3 );

// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
D3DXQUATERNION* WRAP_API D3DXQuaternionBaryCentric
    ( D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ1,
      const D3DXQUATERNION *pQ2, const D3DXQUATERNION *pQ3,
      float f, float g );


///////////////////////////////////////////////////////////////////////////////
// D3DXPLANE
///////////////////////////////////////////////////////////////////////////////

// Normalize plane (so that |a,b,c| == 1)
D3DXPLANE* WRAP_API D3DXPlaneNormalize
    ( D3DXPLANE *pOut, const D3DXPLANE *pP);

// Find the intersection between a plane and a line.  If the line is
// parallel to the plane, NULL is returned.
D3DXVECTOR3* WRAP_API D3DXPlaneIntersectLine
    ( D3DXVECTOR3 *pOut, const D3DXPLANE *pP, const D3DXVECTOR3 *pV1,
      const D3DXVECTOR3 *pV2);

// Construct a plane from a point and a normal
D3DXPLANE* WRAP_API D3DXPlaneFromPointNormal
    ( D3DXPLANE *pOut, const D3DXVECTOR3 *pPoint, const D3DXVECTOR3 *pNormal);

// Construct a plane from 3 points
D3DXPLANE* WRAP_API D3DXPlaneFromPoints
    ( D3DXPLANE *pOut, const D3DXVECTOR3 *pV1, const D3DXVECTOR3 *pV2,
      const D3DXVECTOR3 *pV3);

// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransform
    ( D3DXPLANE *pOut, const D3DXPLANE *pP, const D3DXMATRIX *pM );
    
// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WRAP_API D3DXPlaneTransformArray
    ( D3DXPLANE *pOut, uint32_t OutStride, const D3DXPLANE *pP, uint32_t PStride, const D3DXMATRIX *pM, uint32_t n );



///////////////////////////////////////////////////////////////////////////////
// D3DXCOLOR
///////////////////////////////////////////////////////////////////////////////

// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
D3DXCOLOR* WRAP_API D3DXColorAdjustSaturation
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s);

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
D3DXCOLOR* WRAP_API D3DXColorAdjustContrast
    (D3DXCOLOR *pOut, const D3DXCOLOR *pC, float c);