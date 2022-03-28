#pragma once
//------------------------------------------------------------------------------
/// \file
/// \brief Signals that can be called when performing idw or kriging
/// interpolation. Used by GMS with Pilot Points.
/// \ingroup interpolate
/// \copyright (C) Copyright Aquaveo 2018. Distributed under FreeBSD License
/// (See accompanying file LICENSE or https://aqaveo.com/bsd/license.txt)
//------------------------------------------------------------------------------

//----- Included files ---------------------------------------------------------
#include <xmsinterp/xmsinterp_export.h>
#include <boost/signals2.hpp>

//----- Forward declarations ---------------------------------------------------

//----- Namespace declaration --------------------------------------------------
namespace xms
{
//----- Constants / Enumerations -----------------------------------------------

//----- Structs / Classes ------------------------------------------------------

//----- Function prototypes ----------------------------------------------------
XMSINTERP_EXPORT void inSetDataIndex(int val);
XMSINTERP_EXPORT void inFillWtArray(int id, double wt);

namespace interp
{
namespace connectSet
{
XMSINTERP_EXPORT boost::signals2::connection SetDataIndex(
  const boost::signals2::signal<void(int)>::slot_type& a_slot);
XMSINTERP_EXPORT boost::signals2::connection FillWtArray(
  const boost::signals2::signal<void(int, double)>::slot_type& a_slot);
}
}

} // namespace xms
