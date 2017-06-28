# -*- coding: utf-8 -*-
# =====================================================================================================================
# These bindings were automatically generated by cyWrap. Please do dot modify.
# Additional functionality shall be implemented in sub-classes.
#
__copyright__ = "Copyright 2016 EPFL BBP-project"
# =====================================================================================================================
from cython.operator cimport dereference as deref
from libcpp cimport bool
cimport std
cimport steps_wm

# ======================================================================================================================
cdef extern from "steps/geom/tmpatch.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------

    ###### Cybinding for TmPatch ######
    cdef cppclass TmPatch:
        TmPatch(std.string, Tetmesh*, std.vector[unsigned int], steps_wm.Comp*, steps_wm.Comp*)
        std.vector[bool] isTriInside(std.vector[unsigned int])
        std.vector[unsigned int] getAllTriIndices()
        std.vector[double] getBoundMin()
        std.vector[double] getBoundMax()

# ======================================================================================================================
cdef extern from "steps/geom/memb.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------
    # ctypedef Memb* MembP
    # ctypedef std.map[std.string,Memb*] MembPMap
    # ctypedef std.map[std.string,Memb*].iterator MembPMapI
    # ctypedef std.map[std.string,Memb*].const_iterator MembPMapCI
    # ctypedef std.vector[Memb*] MembPVec
    # ctypedef std.vector[Memb*].iterator MembPVecI
    # ctypedef std.vector[Memb*].const_iterator MembPVecCI

    ###### Cybinding for Memb ######
    cdef cppclass Memb:
        Memb(std.string, Tetmesh*, std.vector[TmPatch*], bool, unsigned int, double, std.string)
        Tetmesh* getContainer()
        std.string getID()
        std.vector[bool] isTriInside(std.vector[unsigned int])
        std.vector[unsigned int] getAllTriIndices()
        unsigned int countTris()
        std.vector[unsigned int] getAllVolTetIndices()
        unsigned int countVolTets()
        std.vector[unsigned int] getAllVirtTriIndices()
        unsigned int countVirtTris()
        std.vector[unsigned int] getAllVertIndices()
        unsigned int countVerts()
        bool open()

# ======================================================================================================================
cdef extern from "steps/geom/tmcomp.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------

    ###### Cybinding for TmComp ######
    cdef cppclass TmComp:
        TmComp(std.string, Tetmesh*, std.vector[unsigned int])
        void setVol(double)
        std.vector[unsigned int] getAllTetIndices()
        unsigned int countTets()
        std.vector[bool] isTetInside(std.vector[unsigned int])
        std.vector[double] getBoundMin()
        std.vector[double] getBoundMax()

# ======================================================================================================================
cdef extern from "steps/geom/diffboundary.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------
    # ctypedef DiffBoundary* DiffBoundaryP
    # ctypedef std.map[std.string,DiffBoundary*] DiffBoundaryPMap
    # ctypedef std.map[std.string,DiffBoundary*].iterator DiffBoundaryPMapI
    # ctypedef std.map[std.string,DiffBoundary*].const_iterator DiffBoundaryPMapCI
    # ctypedef std.vector[DiffBoundary*] DiffBoundaryPVec
    # ctypedef std.vector[DiffBoundary*].iterator DiffBoundaryPVecI
    # ctypedef std.vector[DiffBoundary*].const_iterator DiffBoundaryPVecCI

    ###### Cybinding for DiffBoundary ######
    cdef cppclass DiffBoundary:
        DiffBoundary(std.string, Tetmesh*, std.vector[unsigned int])
        std.string getID()
        void setID(std.string)
        Tetmesh* getContainer()
        std.vector[bool] isTriInside(std.vector[unsigned int])
        std.vector[unsigned int] getAllTriIndices()
        std.vector[steps_wm.Comp*] getComps()

# ======================================================================================================================
cdef extern from "steps/geom/sdiffboundary.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------

    ###### Cybinding for SDiffBoundary ######
    cdef cppclass SDiffBoundary:
        SDiffBoundary(std.string, Tetmesh*, std.vector[unsigned int], std.vector[TmPatch*])
        std.string getID()
        void setID(std.string)
        Tetmesh* getContainer()
        std.vector[bool] isBarInside(std.vector[unsigned int])
        std.vector[unsigned int] getAllBarIndices()
        std.vector[steps_wm.Patch*] getPatches()

# ======================================================================================================================
cdef extern from "steps/geom/tetmesh.hpp" namespace "steps::tetmesh":
# ----------------------------------------------------------------------------------------------------------------------
    cdef enum ElementType:
        ELEM_VERTEX
        ELEM_TRI
        ELEM_TET
        ELEM_UNDEFINED

    ###### Cybinding for ROISet ######
    cdef cppclass ROISet:
        ElementType type
        std.vector[unsigned int] indices
        ROISet()
        ROISet(ElementType, std.set[unsigned int])

    ###### Cybinding for Tetmesh ######
    cdef cppclass Tetmesh:
        Tetmesh(std.vector[double], std.vector[unsigned int], std.vector[unsigned int])
        Tetmesh(std.vector[double], std.vector[unsigned int], std.vector[double], std.vector[double], std.vector[int], std.vector[unsigned int], std.vector[double], std.vector[double], std.vector[unsigned int], std.vector[int])
        std.vector[double] getVertex(unsigned int)
        unsigned int countVertices()
        std.vector[unsigned int] getBar(unsigned int)
        unsigned int countBars()
        std.vector[unsigned int] getTri(unsigned int)
        unsigned int countTris()
        double getTriArea(unsigned int)
        std.vector[unsigned int] getTriBars(unsigned int)
        std.vector[double] getTriBarycenter(unsigned int)
        std.vector[double] getTriNorm(unsigned int)
        TmPatch* getTriPatch(unsigned int)
        void setTriPatch(unsigned int, TmPatch*)
        void setTriDiffBoundary(unsigned int, DiffBoundary*)
        DiffBoundary* getTriDiffBoundary(unsigned int)
        std.vector[int] getTriTetNeighb(unsigned int)
        std.vector[int] getTriTriNeighb(unsigned int, TmPatch*)
        std.set[unsigned int] getTriTriNeighbs(unsigned int)
        std.vector[unsigned int] getTet(unsigned int)
        unsigned int countTets()
        double getTetVol(unsigned int)
        double getTetQualityRER(unsigned int)
        std.vector[double] getTetBarycenter(unsigned int)
        TmComp* getTetComp(unsigned int)
        void setTetComp(unsigned int, TmComp*)
        std.vector[unsigned int] getTetTriNeighb(unsigned int)
        std.vector[int] getTetTetNeighb(unsigned int)
        int findTetByPoint(std.vector[double])
        std.vector[double] getBoundMin()
        std.vector[double] getBoundMax()
        double getMeshVolume()
        std.vector[int] getSurfTris()
        std.vector[double] getBatchTetBarycentres(std.vector[unsigned int])
        void getBatchTetBarycentresNP(unsigned int*, int, double*, int)
        std.vector[double] getBatchTriBarycentres(std.vector[unsigned int])
        void getBatchTriBarycentresNP(unsigned int*, int, double*, int)
        std.vector[double] getBatchVertices(std.vector[unsigned int])
        void getBatchVerticesNP(unsigned int*, int, double*, int)
        std.vector[unsigned int] getBatchTris(std.vector[unsigned int])
        void getBatchTrisNP(unsigned int*, int, unsigned int*, int)
        std.vector[unsigned int] getBatchTets(std.vector[unsigned int])
        void getBatchTetsNP(unsigned int*, int, unsigned int*, int)
        unsigned int getTriVerticesSetSizeNP(unsigned int*, int)
        unsigned int getTetVerticesSetSizeNP(unsigned int*, int)
        void getTriVerticesMappingSetNP(unsigned int*, int, unsigned int*, int, unsigned int*, int)
        void getTetVerticesMappingSetNP(unsigned int*, int, unsigned int*, int, unsigned int*, int)
        void genPointsInTet(unsigned int, unsigned int, double*, int)
        void genPointsInTri(unsigned int, unsigned int, double*, int)
        void genTetVisualPointsNP(unsigned int*, int, unsigned int*, int, double*, int)
        void genTriVisualPointsNP(unsigned int*, int, unsigned int*, int, double*, int)
        void getBatchTetVolsNP(unsigned int*, int, double*, int)
        void getBatchTriAreasNP(unsigned int*, int, double*, int)
        void reduceBatchTetPointCountsNP(unsigned int*, int, unsigned int*, int, double)
        void reduceBatchTriPointCountsNP(unsigned int*, int, unsigned int*, int, double)
        void addROI(std.string, ElementType, std.set[unsigned int])
        void removeROI(std.string)
        void replaceROI(std.string, ElementType, std.set[unsigned int])
        ElementType getROIType(std.string)
        std.vector[unsigned int] getROIData(std.string)
        unsigned int getROIDataSize(std.string)
        unsigned int getNROIs()
        ROISet getROI(std.string)
        std.vector[std.string] getAllROINames()
        bool checkROI(std.string, ElementType, unsigned int, bool)
        std.vector[double] getROITetBarycentres(std.string)
        void getROITetBarycentresNP(std.string, double*, int)
        std.vector[double] getROITriBarycentres(std.string)
        void getROITriBarycentresNP(std.string, double*, int)
        std.vector[double] getROIVertices(std.string)
        void getROIVerticesNP(std.string, double*, int)
        std.vector[unsigned int] getROITris(std.string)
        void getROITrisNP(std.string, unsigned int*, int)
        std.vector[unsigned int] getROITets(std.string)
        void getROITetsNP(std.string, unsigned int*, int)
        unsigned int getROITriVerticesSetSizeNP(std.string)
        unsigned int getROITetVerticesSetSizeNP(std.string)
        void getROITriVerticesMappingSetNP(std.string, unsigned int*, int, unsigned int*, int)
        void getROITetVerticesMappingSetNP(std.string, unsigned int*, int, unsigned int*, int)
        void genROITetVisualPointsNP(std.string, unsigned int*, int, double*, int)
        void genROITriVisualPointsNP(std.string, unsigned int*, int, double*, int)
        void getROITetVolsNP(std.string, double*, int)
        void getROITriAreasNP(std.string, double*, int)
        double getROIVol(std.string)
        double getROIArea(std.string)
        void reduceROITetPointCountsNP(std.string, unsigned int*, int, double)
        void reduceROITriPointCountsNP(std.string, unsigned int*, int, double)