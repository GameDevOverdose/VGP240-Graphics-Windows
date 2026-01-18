#include "PrimativesManager.h"
#include "Rasterizer.h"

PrimativesManager* PrimativesManager::Get()
{
	static PrimativesManager sInstance;
	return &sInstance;
}

PrimativesManager::PrimativesManager()
{

}

bool PrimativesManager::BeginDraw(Topology topology)
{
	mVertexBuffer.clear();
	mToplogy = topology;
	mDrawBegin = true;

	return true;
}

void PrimativesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

bool PrimativesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return false;
	}

	Rasterizer* rasterizer = Rasterizer::Get();

	switch (mToplogy)
	{
	case Topology::Point:
	{
		for (uint32_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			rasterizer->DrawPoint(mVertexBuffer[i]);
		}
	}
	break;
	case Topology::Line:
	{
		for (uint32_t i = 1; i < mVertexBuffer.size(); i += 2)
		{
			rasterizer->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
		}
	}
	break;
	case Topology::Triangle:
	{
		for (uint32_t i = 2; i < mVertexBuffer.size(); i += 3)
		{
			rasterizer->DrawTriangle(mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i]);
		}
	}
	break;
	default:
		return false;
	}
}