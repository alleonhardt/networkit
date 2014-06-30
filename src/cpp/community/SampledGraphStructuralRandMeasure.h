/*
 * SampledRandMeasure.h
 *
 *  Created on: 01.07.2013
 *      Author: cls
 */

#ifndef SAMPLEDGRAPHSTRUCTURALRANDMEASURE_H_
#define SAMPLEDGRAPHSTRUCTURALRANDMEASURE_H_

#include "DissimilarityMeasure.h"

namespace NetworKit {

/**
 * @ingroup community
 * The graph-structural Rand measure assigns a similarity value in [0,1]
 * to two partitions of a graph, by considering connected pairs of nodes.
 * This implementation approximates the index by sampling.
 */
class SampledGraphStructuralRandMeasure: public NetworKit::DissimilarityMeasure {

public:

	/**
	 * Constructs the SampledGraphStructuralRandMeasure. A maximum of @a maxSamples samples are drawn.
	 *
	 * @param maxSamples The amount of samples to draw.
	 */
	SampledGraphStructuralRandMeasure(count maxSamples);

	/** Default destructor */
	virtual ~SampledGraphStructuralRandMeasure();

	virtual double getDissimilarity(Graph& G, Partition& first, Partition& second);

protected:

	count maxSamples;

};

} /* namespace NetworKit */
#endif /* SAMPLEDGRAPHSTRUCTURALRANDMEASURE_H_ */
