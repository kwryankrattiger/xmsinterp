#pragma once
//------------------------------------------------------------------------------
/// \file
/// \ingroup interpolate
/// \copyright (C) Copyright Aquaveo 2018. Distributed under the xmsng
///  Software License, Version 1.0. (See accompanying file
///  LICENSE_1_0.txt or copy at http://www.aquaveo.com/xmsng/LICENSE_1_0.txt)
//------------------------------------------------------------------------------

//----- Included files ---------------------------------------------------------
#include <xmscore/misc/base_macros.h>
#include <xmsinterp/interpolate/InterpBase.h>
#include <xmscore/points/ptsfwd.h>
#include <xmscore/misc/boost_defines.h>

//----- Forward declarations ---------------------------------------------------

//----- Namespace declaration --------------------------------------------------
namespace xms
{
class Observer;

//----- Constants / Enumerations -----------------------------------------------

//----- Structs / Classes ------------------------------------------------------
/// \brief Class that performs inverse distance weighted interpolation
/// \see InterpIdwImpl
class InterpIdw : public InterpBase
{
public:
  static BSHP<InterpIdw> New();

  /// Weight calculation method enumeration
  enum WeightEnum { CLASSIC, MODIFIED };
  /// Nodal fuction type enumeration
  enum NodalFuncEnum { CONSTANT, GRAD_PLANE, QUADRATIC };

  /// \cond

  virtual void SetPtsTris(BSHP<std::vector<Pt3d>> a_, BSHP<std::vector<int>> a_tris) override = 0;
  virtual void SetPts(BSHP<std::vector<Pt3d>> a_, bool a_2d) = 0;
  virtual float InterpToPt(const Pt3d& a_pt) override = 0;
  // this method will run parallel
  virtual void InterpToPts(const std::vector<Pt3d>& a_pts,
                           std::vector<float>& a_scalars) override = 0;
  virtual void SetPtActivity(DynBitset& a_activity) override = 0;
  // bitset is number of triangles in length not numtri*3 like the tris array
  virtual void SetTriActivity(DynBitset& a_activity) override = 0;
  virtual BSHP<std::vector<Pt3d>> GetPts() override = 0;
  virtual BSHP<std::vector<int>> GetTris() override = 0;
  virtual void SetTrunc(double a_sMax, double a_sMin) override = 0;

  // various IDW options
  virtual void SetObserver(BSHP<Observer> a_) = 0;
  virtual void SetPower(double a_) = 0;
  virtual void SetSearchOpts(int a_nNearestPoints, bool a_quad_oct_Search) = 0;
  virtual void SetWeightCalcMethod(WeightEnum a_) = 0;
  virtual void SetNodalFunction(NodalFuncEnum a_,
                                int a_nNearests,
                                bool a_quad_oct,
                                BSHP<Observer> a_prog) = 0;

  virtual void SetSaveWeights(bool a_) = 0; // used by pilot points

  virtual void InterpWeights(
    const Pt3d& a_pt, // interp weights from the points to the passed in a_pt
    std::vector<int>& a_idx,
    std::vector<double>& a_wt) const = 0;

  virtual void SetMultiThreading(bool a_) = 0;

  virtual std::string ToString() const override = 0;
  virtual void SetIdString(const std::string& a_id) override = 0;
  virtual std::string GetIdString() const override = 0;

private:
  XM_DISALLOW_COPY_AND_ASSIGN(InterpIdw);
  /// \endcond

protected:
  InterpIdw();
  virtual ~InterpIdw();
};
//----- Function prototypes ----------------------------------------------------
}