/**
* \file ExactCubic.h
* \brief class allowing to create an Exact cubic spline.
* \author Steve T.
* \version 0.1
* \date 06/17/2013
*
* This file contains definitions for the ExactCubic class.
* Given a set of waypoints (x_i*) and timestep (t_i), it provides the unique set of
* cubic splines fulfulling those 4 restrictions :
* - x_i(t_i) = x_i* ; this means that the curve passes trough each waypoint
* - x_i(t_i+1) = x_i+1* ;
* - its derivative is continous at t_i+1
* - its acceleration is continous at t_i+1
* more details in paper "Task-Space Trajectories via Cubic Spline Optimization"
* By J. Zico Kolter and Andrew Y.ng (ICRA 2009)
*/


#ifndef _CLASS_EXACTCUBIC
#define _CLASS_EXACTCUBIC

#include "Curve_ABC.h"

#include "Exports.h"
#include "MathDefs.h"

#include <memory>
#include <vector>

namespace spline
{
	struct CubicPImpl; // private implementation
	/// \class ExactCubic
	/// \brief Represents a set of cubic splines defining a continuous function 
	/// crossing each of the waypoint given in its initialization
	///
	struct ExactCubic : public Curve_ABC
	{
/* Constructors - destructors */
	public:
		///\brief Constructor
		///\param waypoints : a list comprising at least 2 waypoints in ascending time order
		SPLINE_API ExactCubic(const T_Waypoint& /*waypoints*/);

		///\brief Destructor
		SPLINE_API ~ExactCubic();

	private:
		ExactCubic(const ExactCubic&);
		ExactCubic& operator=(const ExactCubic&);
/* Constructors - destructors */

/*Operations*/
	public:
	///  \brief Evaluation of the cubic spline at time t.
	///  \param t : the time when to evaluate the spine
	///  \param result : a reference to the Point set to the x(t)
	///  \return : true if evaluation is successful, false if t is out of range
	SPLINE_API virtual bool Evaluate(const Real /*t*/, Vector3& /*result*/) const;
/*Operations*/

/*Helpers*/
	public:
	SPLINE_API Real virtual MinBound() const;
	SPLINE_API Real virtual MaxBound() const;
/*Helpers*/

/*Attributes*/
	private:
		std::auto_ptr<CubicPImpl> pImpl_;
/*Attributes*/
	};
}
#endif //_CLASS_EXACTCUBIC

