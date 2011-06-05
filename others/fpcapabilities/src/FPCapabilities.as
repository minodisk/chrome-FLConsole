package  {
	import flash.display.Sprite;
	import flash.external.ExternalInterface;
	import flash.system.Capabilities;
	
	/**
	 * @langversion ActionScript 3.0
	 * @playerversion 9.0
	 * @author dsk
	 * @since 2011/05/31
	 */
	public class FPCapabilities extends Sprite {
		
		public function FPCapabilities() {
			if (ExternalInterface.available) {
				ExternalInterface.addCallback('isDebugger', _isDebugger);
				ExternalInterface.call(loaderInfo.parameters.onReady);
			}
		}
		
		private function _isDebugger():Boolean {
			return Capabilities.isDebugger;
		}
		
		
	}
	
	
}
