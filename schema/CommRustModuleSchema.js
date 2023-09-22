// @flow

'use strict';

import { TurboModuleRegistry } from 'react-native';
import type { TurboModule } from 'react-native/Libraries/TurboModule/RCTExport.js';

export interface Spec extends TurboModule {
 
  +add: (
  a: number,
  b: number,
) => Promise < string >;
}

export default (TurboModuleRegistry.getEnforcing < Spec > (
  'CommRustTurboModule',
): Spec);
