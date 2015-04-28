#ifndef xHeinz_Solver_Config_HPP
#define xHeinz_Solver_Config_HPP

#include <limits>
#include <iosfwd>
#include <array>

namespace xHeinz {
namespace solver {

 struct Config {
   enum ConnectivityType: int { SumUnits      = 0
                              , SumWeights    = 1
                              , SumPosUnits   = 2
                              , SumPosWeights = 3
                              };

   double connectivityPercentage;
   std::array< double, 2 > positivePercentage;
   ConnectivityType connectivityType;
   int numThreads;
   int size;
   int maxCutIterations;
   double timeLimit;
   double rootTimeLimit;
   double gapObjective;
   double cutLo;
   bool noConnectivity;

   Config( double cp = 0.6
         , std::array< double, 2 > pp = std::array< double, 2 >{ 0.0, 0.0 }
         , ConnectivityType ct = SumUnits
         , int threads = 1
         , int s = -1
         , int mi = 20
         , double tl = std::numeric_limits< double >::infinity()
         , double rtl = std::numeric_limits< double >::infinity()
         , double go = -1
         , double cl = -1
         , bool nc = false
         )
     : connectivityPercentage{ cp }
     , positivePercentage( pp )
     , connectivityType{ ct }
     , numThreads{ threads }
     , size{ s }
     , maxCutIterations{ mi }
     , timeLimit{ tl }
     , rootTimeLimit{ rtl }
     , gapObjective{ go }
     , cutLo{ cl }
     , noConnectivity{ nc } {
   }

   friend std::ostream & operator<<( std::ostream & out, Config const & conf );
 };

} // namespace xHeinz
} // namespace xHeinz

#endif // xHeinz_Solver_Config_HPP

/* vim: set ts=8 sw=2 sts=2 et : */
