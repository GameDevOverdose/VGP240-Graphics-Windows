#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimativesManager
{
public:
	static PrimativesManager* Get();

	//Start accepting vertices
	bool BeginDraw(Topology topology);
	//Add vertices to the list, only if drawing is enabled
	void AddVertex(const Vertex& vertex);
	//Send all vertices to Rasterizer
	bool EndDraw();

private:
	PrimativesManager();

	std::vector <Vertex> mVertexBuffer;
	Topology mToplogy = Topology::Point;
	bool mDrawBegin = false;
};