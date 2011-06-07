package  {
	import com.adobe.serialization.json.JSON;
	import flash.display.Graphics;
	import flash.display.Sprite;
	import flash.display.StageAlign;
	import flash.display.StageQuality;
	import flash.display.StageScaleMode;
	import flash.events.MouseEvent;
	import flash.geom.Point;
	import flash.net.URLLoader;
	import flash.net.URLRequest;
	
	/**
	 * @langversion ActionScript 3.0
	 * @playerversion 10.0
	 * @author minodisk
	 * @since 2011/05/25
	 */
	public class FLConsoleTest extends Sprite {
		
		private var _traceButton:Button;
		private var _errorButton:Button;
		private var _y:int;
		
		public function FLConsoleTest() {
			super();
			
			stage.align = StageAlign.TOP_LEFT;
			stage.quality = StageQuality.HIGH;
			stage.scaleMode = StageScaleMode.NO_SCALE;
			
			var g:Graphics = graphics;
			g.beginFill(0xEEEEEE);
			g.drawRect(0, 0, stage.stageWidth, stage.stageHeight);
			g.endFill();
			
			_y = 10;
			
			_addLabel('Intended Case');
			_addButton('trace(null);', function (e:MouseEvent):void {
				trace(null);
			});
			_addButton('trace(undefined);', function (e:MouseEvent):void {
				trace(undefined);
			});
			_addButton('trace(true);', function (e:MouseEvent):void {
				trace(true);
			});
			_addButton('race(3);', function (e:MouseEvent):void {
				trace(3);
			});
			_addButton('trace("");', function (e:MouseEvent):void {
				trace("");
			});
			_addButton('trace("abc");', function (e:MouseEvent):void {
				trace("abc");
			});
			_addButton('trace("\\\" double quart, \' single quart, / slash, \\ backslash");', function (e:MouseEvent):void {
				trace("\" double quart, ' single quart, / slash, \\ backslash");
			});
			_addButton('trace(new Date());', function (e:MouseEvent):void {
				trace(new Date());
			});
			_addButton('trace(<data><book id="0123">Flash</book></data>);', function (e:MouseEvent):void {
				trace(<data><book id="0123">Flash</book></data>);
			});
			_addButton('trace((<data><book id="0001">ActionScript</book><book id="0002">JavaScript</book></data>).book);', function (e:MouseEvent):void {
				trace((<data><book id="0001">ActionScript</book><book id="0002">JavaScript</book></data>).book);
			});
			_addButton('trace(JSON.encode({boolean: true, number: 3, string: "3", array: ["abc", new Date()]}));', function (e:MouseEvent):void {
				trace(JSON.encode({boolean: true, number: 3, string: "3", array: ["abc", new Date()]}));
			});
			_addButton('var ldr:URLLoader = new URLLoader(); ldr.load(new URLRequest("http://www.google.com/"));', function (e:MouseEvent):void {
				var ldr:URLLoader = new URLLoader(); ldr.load(new URLRequest("http://www.google.com/"));
			});
			_addButton('var ldr:URLLoader = new URLLoader(); ldr.load(new URLRequest("dummy.txt"));', function (e:MouseEvent):void {
				var ldr:URLLoader = new URLLoader(); ldr.load(new URLRequest("dummy.txt"));
			});
			_addButton('var i:int = 10; while (i--) { trace(i); }', function (e:MouseEvent):void {
				var i:int = 10; while (i--) { trace(i); }
			});
			
			_addSpace();
			
			_addLabel('Unintended Case');
			_addButton('race("3");', function (e:MouseEvent):void {
				trace("3");
			});
			_addButton('trace("0\\n1\\n2\\n3\\n4\\n5\\n6\\n7\\n8\\n9");', function (e:MouseEvent):void {
				trace("0\n1\n2\n3\n4\n5\n6\n7\n8\n9");
			});
			
			trace('flash_tracer_test.swf::height=' + (_y + 10).toString() + 'px');
		}
		
		private function _addButton(text:String, method:Function):void {
			_errorButton = new Button(text);
			_errorButton.addEventListener(MouseEvent.CLICK, method);
			_errorButton.x = 10;
			_errorButton.y = _y;
			addChild(_errorButton);
			
			_y += 30;
		}
		
		private function _addLabel(str:String):void {
			var label:Label = new Label(str, 14, 0x333333);
			label.x = 10;
			label.y = _y;
			addChild(label);
			
			_y += 25;
		}
		
		private function _addSpace():void {
			_y += 10;
		}
		
		
	}
	
	
}

	import flash.display.Graphics;
	import flash.display.Sprite;
	import flash.events.MouseEvent;
	import flash.geom.ColorTransform;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.text.TextFormat;

	internal class Button extends Sprite {
		
		static private const LIGHT:ColorTransform = new ColorTransform(1, 1, 1, 1, 100, 100, 100, 0);
		static private const DARK:ColorTransform  = new ColorTransform(1, 1, 1, 1, 0, 0, 0, 0);
		
		public function Button(str:String) {
			buttonMode = true;
			
			var g:Graphics = graphics;
			g.beginFill(0x333333);
			g.drawRect(0, 0, 580, 20);
			g.endFill();
			
			var label:Label = new Label(str);
			addChild(label);
			
			addEventListener(MouseEvent.ROLL_OVER, _lighten);
			addEventListener(MouseEvent.ROLL_OUT, _darken);
		}
		
		private function _lighten(e:MouseEvent):void {
			transform.colorTransform = LIGHT;
		}
		
		private function _darken(e:MouseEvent):void {
			transform.colorTransform = DARK;
		}
	}
	
	internal class Label extends TextField {
		
		public function Label(str:String, size:int = 11, color:uint = 0xFFFFFF) {
			defaultTextFormat = new TextFormat('_sans', size, color, true);
			autoSize = TextFieldAutoSize.LEFT;
			multiline = false;
			text = str;
			mouseEnabled = false;
		}
	}
