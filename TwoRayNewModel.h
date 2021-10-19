#ifndef __INET_TWORAYNEWMODEL_H_
#define __INET_TWORAYNEWMODEL_H_


#include <inet/physicallayer/contract/packetlevel/IPathLoss.h>
#include <complex>

namespace inet {
namespace physicallayer {

class INET_API TwoRayNewModel : public cModule, public IPathLoss
{
public:
    TwoRayNewModel();
    void initialize(int stage) override;
    double computePathLoss(const ITransmission*, const IArrival*) const override;
    double computePathLoss(mps propagation, Hz frequency, m distance) const override;
    m computeRange(mps propagation, Hz frequency, double loss) const override;
    std::ostream& printToStream(std::ostream&, int level) const override;

protected:
    double epsilon_r;
    double sigma;
    double delta_h;
    char polarization;

protected:
    virtual double computeTwoRayNewModel(const Coord& posTx, const Coord& posRx, m waveLength) const;
    virtual double terraPlana(const Coord& posTx, const Coord& posRx, m waveLength) const;
    virtual double terraEsferica(const Coord& posTx, const Coord& posRx, m waveLength) const;
};

} // namespace physicallayer
} // namespace inet

#endif /* __TWORAYNEWMODEL_H_ */
